#include <stdio.h>
#include <stdlib.h>
#include "sqlite/sqlite3.h"

int main (void){

    // Declaramos labase de datos de SQLite
    sqlite3 *db; // Puntero a la base de datos
    int rc; // Entero para almacenar el retorno de las funciones de la base de datos
    char *errMsg = 0; // Mensaje de error para operaciones SQLite

    // Creamos (o abrimos), la base de datos
    rc = sqlite3_open("futbol.sqlite", &db);
    if (rc != SQLITE_OK){
        printf("No se pudo abrir la base de datos: %s.", sqlite3_errmsg(db));
        return 1;
    }

    // Habilitamos las foreign keys
    rc = sqlite3_exec(db, "PRAGMA foreign_keys = ON;", NULL, NULL, &errMsg);
    if (rc != SQLITE_OK){
        printf("Error habilitando las 'foreign keys': %s.", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    // Creamos la tabla "equipos"
    const char *sqlEquipos = "CREATE TABLE IF NOT EXISTS equipos ("
                             "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                             "nombre TEXT NOT NULL);";

    // Ejecutamos la operación para crear la tabla "equipos"
    rc = sqlite3_exec(db, sqlEquipos, 0, 0, &errMsg);
    if (rc != SQLITE_OK){
        printf("Error creando la tabla equipos: %s.", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    // Creamos la tabla "campeonatos"
    const char *sqlCampeonatos = "CREATE TABLE IF NOT EXISTS campeonatos ("
                                 "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                                 "nombre TEXT NOT NULL,"
                                 "campeon INTEGER NOT NULL,"
                                 "FOREIGN KEY (campeon) REFERENCES equipos (id));";

    // Ejecutamos la operación para crear la tabla "campeonatos"
    rc = sqlite3_exec(db, sqlCampeonatos, 0, 0, &errMsg);
    if (rc != SQLITE_OK){
        printf("Error creando la tabla campeonatos.: %s.", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    // Insertamos en las tablas los valores inciales
    const char *sqlInsertInitialData = 
        "INSERT OR IGNORE INTO equipos (nombre) VALUES ('Athletic Club');"
        "INSERT OR IGNORE INTO equipos (nombre) VALUES ('Real Sociedad');"
        "INSERT OR IGNORE INTO equipos (nombre) VALUES ('F.C. Barcelona');"
        "INSERT OR IGNORE INTO equipos (nombre) VALUES ('Real Madrid C.F.');"
        "INSERT OR IGNORE INTO equipos (nombre) VALUES ('Valencia C.F');"
        "INSERT OR IGNORE INTO campeonatos (nombre, campeon) VALUES ('Liga 2017-18', 3);"
        "INSERT OR IGNORE INTO campeonatos (nombre, campeon) VALUES ('Liga 2018-19', 3);"
        "INSERT OR IGNORE INTO campeonatos (nombre, campeon) VALUES ('Liga 2019-20', 4);"
        "INSERT OR IGNORE INTO campeonatos (nombre, campeon) VALUES ('Copa 2017-18', 3);"
        "INSERT OR IGNORE INTO campeonatos (nombre, campeon) VALUES ('Copa 2018-19', 5);"
        "INSERT OR IGNORE INTO campeonatos (nombre, campeon) VALUES ('Copa 2019-20', 2);";

    // Ejecutamos la operación de insertar los valores iniciales en las tablas
    rc = sqlite3_exec(db, sqlInsertInitialData, 0, 0, &errMsg);
    if (rc != SQLITE_OK){
        printf("Error en la inserción de los datos iniciales: %s.", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    // Insertar en la tabla "campeonatos" una nueva fila
    const char *sqlInsertData = "INSERT INTO campeonatos (nombre, campeon) VALUES ('Copa 2020-21', 3);";

    // Ejecutamos la operación de insertar una nueva fila en la tabla "campeonatos"
    rc = sqlite3_exec(db, sqlInsertData, 0, 0, &errMsg);
    if (rc != SQLITE_OK){
        printf("Error en la inserción de la nueva fila en la tabla campeonatos: %s.", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    // Consulta de los campeonatos ganados por el F.C. Barcelona
    const char *sqlSelect = 
                "SELECT c.nombre FROM campeonatos c "
                "JOIN equipos e ON c.campeon = e.id "
                "WHERE e.nombre = 'F.C. Barcelona';";

    // Preparamos la consulta
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sqlSelect, -1, &stmt, NULL);
    if (rc != SQLITE_OK){
        printf("Error preparando la consulta de los campeonatos ganados por el F.C. Barcelona en la base de datos:%s.", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }    

    // Ejecutamos la consulta
    printf("Campeonatos ganados por el F.C. Barcelona:\n");
    while( (rc = sqlite3_step(stmt)) == SQLITE_ROW ){ // Mientras haya filas se ejecuta
        const unsigned char *campeonato = sqlite3_column_text(stmt, 0);
        printf("- %s\n", campeonato);
    }
    if (rc != SQLITE_DONE){ // Comprobamos que el último rc ha sido SQLITE_DONE, indicando que todas las filas se procesaron sin error
        printf("Error al realizar la consulta de los campeonatos ganados por el F.C. Barcelona en la base de datos %s.", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Finalizamos la sentencia, liberando los recursos
    sqlite3_finalize(stmt);

    // Cerrar la base de datos
    sqlite3_close(db);

    return 0;
}