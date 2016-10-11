// hello_world4.cpp
using namespace System;

value class Hello
{
    String^ greeting = "Hi there";

    public:
    void Greet()
    {
        Console::WriteLine(greeting + "!");
    }

    void SetGreeting(String^ newGreeting)
    {
       greeting = newGreeting;
    }

};

int main()
{
   Hello hello;
   hello.Greet("Hello World");
}
