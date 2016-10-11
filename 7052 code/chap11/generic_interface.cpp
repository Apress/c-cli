// generic_interface.cpp
// Declare your generic interfaces and compile to a DLL.
// Reference the compiled assembly using #using.
// Do not reference the source as an included file.

generic <typename T>
public interface class IGInterface
{
   property T InnerObject;
};
