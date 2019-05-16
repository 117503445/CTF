// brianfuck to C
#include <fstream>
#include <string>
using namespace std;
const int max_box_size = 3000;

ifstream fin;
ofstream fout;
void translate_to_c(const char *file_name);
void retract(int n);

int main(int argc, char const *argv[])
{
    for (int i = 0; i < argc; ++i)
    {
        translate_to_c(argv[i]);
    }
    return 0;
}

void translate_to_c(const char *file_name)
{
    fin.open(file_name);
    string target_file_name = file_name;
    target_file_name += ".c";
    fout.open(target_file_name);
    fout << "// file_name : " << target_file_name << endl;
    fout << "// This file is a c soucrce file interpreted from brainfuck souce file " << file_name << ".\n";
    fout << "#include <stdio.h>\n"
         << "#define max_box_size " << max_box_size << endl;
    fout << "char box[max_box_size];\n";
    fout << "char *ptr = box;\n";
    fout << "int main()\n{\n";
    char ch;
    int retract_num = 1;
    while (fin.get(ch))
    {
        switch (ch)
        {
        case '>':
            retract(retract_num);
            fout << "++ptr;\n";
            break;
        case '<':
            retract(retract_num);
            fout << "--ptr;\n";
            break;
        case '+':
            retract(retract_num);
            fout << "++*ptr;\n";
            break;
        case '-':
            retract(retract_num);
            fout << "--*ptr;\n";
            break;
        case '.':
            retract(retract_num);
            fout << "putchar(*ptr);\n";
            break;
        case ',':
            retract(retract_num);
            fout << "*ptr=getchar();\n";
            break;
        case '[':
            retract(retract_num++);
            fout << "while (*ptr) {\n";
            break;
        case ']':
            retract(--retract_num);
            fout << "}\n";
            break;
        }
    }
    fout << "\n return 0;" << endl;
    fout << "}\n";
    fin.close();
    fout.close();
}

void retract(int n)
{
    for (int i = 0; i < n; i++)
        fout << "   ";
}