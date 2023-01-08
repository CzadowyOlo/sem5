
#include <iostream> 
#include <vector>
#include <algorithm>    // std::find_if
#include <map>
#include <string>

using namespace std;

// UWAGI
// 1. potrzebna będzie lista zawierająca pary postaci:
// ( IDENTIFIER, VALUE )
// przy inicjowaniu zmiennej VALUE zostanie ustwione na -1
// (ponieważ z założenia operujemy w języku na liczbach naturalnych)
// gdzie pierwszym elementem listy będzie accumulator
// lista[0] = (acc, value)


// expressions

// void set_val(string &dupa, size_t &k, map<string, int> p, int a);
// void set_val(string &dupa, size_t &k, map<string, int> p, string id);
// void set_val(string &dupa, size_t &k, map<string, int> p, int a){
//     fprintf(f, "SET %d\n", a);
// }
// void set_val(string &dupa, size_t &k, map<string, int> p, string id){
//     fprintf(f, "LOAD %d\n", p[id]);
// }

void set_val(string &dupa, size_t &k, map<string, int> p, string val) {
    k++;
    if (isdigit(val[0]))
        dupa = dupa + "SET " + val + "\n";
        //fprintf(f, "SET %d\n", stoi(val));
    else
        //fprintf(f, "LOAD %d\n", p[val]);
        dupa = dupa + "LOAD " + val + "\n";

}



// void add(string &dupa, size_t &k, map<string, int> p, int a, int b);
// void add(string &dupa, size_t &k, map<string, int> p, string id_a, int a);
// void add(string &dupa, size_t &k, map<string, int> p, int a, string id_b);
// void add(string &dupa, size_t &k, map<string, int> p, string id_a, string id_b);

// void add(string &dupa, size_t &k, map<string, int> p, int a, int b){
//     fprintf(f, "SET %d\n", a+b);
// }
// void add(string &dupa, size_t &k, map<string, int> p, string id_a, int b){
//     fprintf(f, "SET %d\n", b);
//     fprintf(f, "ADD %d\n", p[id_a]);
// }
// void add(string &dupa, size_t &k, map<string, int> p, int a, string id_b){
//     fprintf(f, "SET %d\n", a);
//     fprintf(f, "ADD %d\n", p[id_b]);   
// }
// void add(string &dupa, size_t &k, map<string, int> p, string id_a, string id_b){
//     fprintf(f, "LOAD %d\n", p[id_a]);
//     fprintf(f, "ADD %d\n", p[id_b]);  
// }

void add(string &dupa, size_t &k, map<string, int> p, string v1, string v2)
{

    if (isdigit(v1[0])) {
        int a = stoi(v1);
        if (isdigit(v2[0])) {
            int b = stoi(v2);
            int res = a + b;
            k++;
            dupa = dupa + "SET " + std::to_string(res) + "\n";
            //fprintf(f, "SET %d\n", a+b);   
        }
        else {
            //int key = p[v1];
            if( p.find(v2) == p.end() ){
                cout<<"undeclared variable";
            }

            k+=2;
            dupa = dupa + "SET " + std::to_string(a) + "\n" + "ADD " + std::to_string(p[v2]) + "\n";
            //fprintf(f, "SET %d\n", a);
            //fprintf(f, "ADD %d\n", p[v2]);
        }
    }
    else {
        if (isdigit(v2[0])) {
            if( p.find(v1) == p.end() ){
                cout<<"undeclared variable";
            }
            int b = stoi(v2);
            k+=2;
            dupa = dupa + "SET " + std::to_string(b) + "\n" + "ADD " + std::to_string(p[v1]) + "\n";
            //fprintf(f, "SET %d\n", b);
            //fprintf(f, "ADD %d\n", p[v1]); 
        }
        else {
            if( p.find(v1) == p.end() || p.find(v2) == p.end() ){
                cout<<"undeclared variable";
            }
            k+=2;
            dupa = dupa + "LOAD " + std::to_string(p[v1]) + "\n" + "ADD " + std::to_string(p[v2]) + "\n";
            //fprintf(f, "LOAD %d\n", p[v1]);
            //fprintf(f, "ADD %d\n", p[v2]); 
        }
    }
}

// void sub(int a, int b);
// void mul(int a, int b);
// // void div(int a, int b);
// void mod(int a, int b);

// // conditions
// void is_eq(int a, int b);
// void is_noteq(int a, int b);
// void is_geq(int a, int b);
// void is_leq(int a, int b);
// void is_greater(int a, int b);
// void is_less(int a, int b);

// void write_val(string &dupa, size_t &k, map<string, int> p, int a);
// void write_val(string &dupa, size_t &k, map<string, int> p, string id);
// void write_val(string &dupa, size_t &k, map<string, int> p, int a){
//     fprintf(f, "SET %d\n", a);
//     fprintf(f, "PUT 0\n");
// }
// void write_val(string &dupa, size_t &k, map<string, int> p, string id){
//     fprintf(f, "PUT %d\n", p[id]);
// }

void write_val(string &dupa, size_t &k, map<string, int> p, string val) {
    if (isdigit(val[0])) {
        k+=2;
        dupa = dupa + "SET " + val + "\n" + "PUT 0 \n";
        //fprintf(f, "SET %d\n", stoi(val));
        //fprintf(f, "PUT 0\n");
    }
    else {
        k+=1;
        dupa = dupa + "PUT " + to_string(p[val]) + "\n";
        //fprintf(f, "PUT %d\n", p[val]);
        //fprintf(f, "(Val = %s\t p[Val] = %d)\n", val, p[val]);
    }
}

void read_val(string &dupa, size_t &k, map<string, int> p, string val) {
    //fprintf(f, "GET %d\n", p[val]);
    dupa = dupa + "GET " + to_string(p[val]) + "\n";
    k++;
    //fprintf(f, "(Val = %s\t p[Val] = %d)\n", val, p[val]);string

}

void assign_val(string &dupa, size_t &k, map<string, int> p, string val) {
    //fprintf(f, "STORE %d\n", p[val]);
    dupa = dupa + "STORE " + to_string(p[val]) + "\n";
    k++;

    //fprintf(f, "(Val = %s\t p[Val] = %d)\n", val, p[val]);
}


void is_notequal(string& dupa, size_t& k, map<string, int> p, string v1, string v2){
    if (isdigit(v1[0])) {
        int a = stoi(v1);
        if (isdigit(v2[0])) {
            //oba numy  
        }
        else {
            //v1 num, v2 identifier
       
        }
    }
    else {
        if (isdigit(v2[0])) {
            //v1 identifier, v2 num

        }
        else {
            // oba identifier
            dupa = dupa + 
            "LOAD " + to_string(p[v1]) + "\n" +
            "SUB "  + to_string(p[v2]) + "\n" +
            "JPOS " + to_string(k+5) + "\n" +
            "LOAD " + to_string(p[v2]) + "\n" +
            "SUB "  + to_string(p[v1]) + "\n" +
            "JZERO ";
            k += 6;

        }
    }
}
void is_equal(string& dupa, size_t& k, map<string, int> p, string v1, string v2){
    dupa = dupa + 
    "LOAD " + to_string(p[v1]) + "\n" +
    "SUB "  + to_string(p[v2]) + "\n" +
    "JPOS " + to_string(k+5) + "\n" +
    "LOAD " + to_string(p[v2]) + "\n" +
    "SUB "  + to_string(p[v1]) + "\n" +
    "JPOS ";
    k += 6;
}
void is_greater(string& dupa, size_t& k, map<string, int> p, string v1, string v2){
    dupa = dupa + 
    "LOAD " + to_string(p[v1]) + "\n" +
    "SUB "  + to_string(p[v2]) + "\n" +
    "JZERO ";
    k += 3;
}
void is_less(string& dupa, size_t& k, map<string, int> p, string v1, string v2){
    dupa = dupa + 
    "LOAD " + to_string(p[v2]) + "\n" +
    "SUB "  + to_string(p[v1]) + "\n" +
    "JZERO ";
    k += 3;
}
void is_gequal(string& dupa, size_t& k, map<string, int> p, string v1, string v2){
    dupa = dupa + 
    "LOAD " + to_string(p[v2]) + "\n" +
    "SUB "  + to_string(p[v1]) + "\n" +
    "JPOS ";
    k += 3;
}
void is_lequal(string& dupa, size_t& k, map<string, int> p, string v1, string v2){
    dupa = dupa + 
    "LOAD " + to_string(p[v1]) + "\n" +
    "SUB "  + to_string(p[v2]) + "\n" +
    "JPOS ";
    k += 3;
}


