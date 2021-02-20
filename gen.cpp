#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

  if (argc > 1)
  {

    ofstream outfile(argv[1]);

    outfile << "#include <iostream>" << endl;
    outfile << "using namespace std;" << endl;

    outfile << "int main(int argc, char const *argv[])" << endl;
    outfile << "{" << endl;
    outfile << "    Solution *obj = new Solution();" << endl;

    outfile << "    return 0;" << endl;
    outfile << "}" << endl;

    outfile.close();
  }

  return 0;
}