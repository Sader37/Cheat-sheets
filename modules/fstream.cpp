// fstream
// ofstream|ifstream|fstream file;
// ios::app - append to end of file,
// ios::ate - go to end of file on opening,
// ios::binary - open file in binary mode,
// ios::in - open file for reading only,
// ios::out - open file fro writing only,
// ios::trunc - delete the contents of the file if it exists
// file.open("file.ext", ios::out | ios::trunc); `|` stands for binary AND
// ofstream
// ofstream hw_txt;
// hw_txt.open("hello_world.txt", ios::app | ios::out);
// hw_txt << "Hello world!";
// hw_txt.close();
// ifstream
// ifstream hw_txt;
//  string get_file_contents(ifstream &file, const string fn) {
//      file.open(fn);
//      string contents, tmpl;
//          while (getline(file, tmpl)) {
//              contents += tmpl + "\n";
//          }
//      file.close();
//      return contents;
//  }
