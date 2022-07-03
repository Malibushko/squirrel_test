#include <simplesquirrel/simplesquirrel.hpp>

std::vector<std::string> FileList = 
{
  SQ_SCRIPT_PATH "/Main.nut",
  SQ_SCRIPT_PATH "/Hello.nut"
};

int main() {

  ssq::VM VirtualMachine(1024, ssq::Libs::ALL);

  for (const auto & File : FileList)
  {
    try
    {
      std::cout << "Compiled file: '" << File << "'" << std::endl;

      const auto & Script = VirtualMachine.compileFile(File.c_str());

      VirtualMachine.run(Script);
    }
    catch (std::exception & _Exception)
    {
      std::cout << "Exception occured during file compilation: " << _Exception.what() << std::endl;

      return -1;
    }
  }

  try
  {
    const auto& Func = VirtualMachine.findFunc("main");

    (void)VirtualMachine.callFunc(Func, VirtualMachine);
  }
  catch (std::exception& _Exception)
  {
    std::cout << "Exception occured during function call: " << _Exception.what() << std::endl;

    return -1;
  }


  return 0;
}