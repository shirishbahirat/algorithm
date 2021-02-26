#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

  if (argc < 2)
    return 0;

  string name = argv[1];

  name += ".cpp";

  ofstream fs;
  fs.open(name);

  fs << "#include <iostream>" << endl;
  fs << "#include <vector>" << endl;
  fs << "" << endl;
  fs << "using namespace std;" << endl;
  fs << "" << endl;
  fs << "class Solution" << endl;
  fs << "{" << endl;
  fs << "public:" << endl;
  fs << "    int pivotIndex(vector<int> &nums)" << endl;
  fs << "    {" << endl;
  fs << "         return 0;" << endl;
  fs << "    }" << endl;
  fs << "};" << endl;

  fs << "int main(int argc, char const *argv[])" << endl;
  fs << "{" << endl;
  fs << "    Solution *obj = new Solution();" << endl;
  fs << "    return 0;" << endl;
  fs << "  }" << endl;

  fs.close();

  return 0;
}
