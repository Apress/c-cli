// template_with_generic_interface.h

#using "generic_interface.dll"

template <typename T>
ref class CTemplate : IGInterface<T>
{
   T m_obj;

   public:

       CTemplate(T obj) { m_obj = obj; }

       virtual property T InnerObject
       {
          T get() { return m_obj; }
          void set(T obj) { m_obj = obj; }
       }

};
