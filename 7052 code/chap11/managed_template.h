// managed_template.h

template <typename T>
public ref class CTemplate
{
   T m_obj;

   public:

       CTemplate(T obj) { m_obj = obj; }

       property T InnerObject
       {
          T get() { return m_obj; }
          void set(T obj) { m_obj = obj; }
       }

};
