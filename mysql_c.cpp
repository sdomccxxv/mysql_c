#include <mysql.h>
#include <iostream>
using namespace std;
int q_estado;

void menu();

int main()
{
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "150289", "db_empresa1", 3306, NULL, 0);
    if (conectar) {
        //cout << "Conexion exitosa..." << endl;
        string puesto;
        cout << "Ingrese puesto: ";
        cin >> puesto;

        string insert = "INSERT INTO puestos(puesto) VALUES ('" + puesto + "')";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar, i);

        if (!q_estado) {
            cout << "Ingreso exitoso..." << endl;
        }
        else {
            cout << "Error al ingresar..." << endl;
        }
    }
    else {
        cout << "Conexion fallida..." << endl;
    }
    //cout << "Hello World!\n";
    system("pause");
    return 0;
    
}

