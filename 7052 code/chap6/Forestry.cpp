// Forestry.cpp
using namespace System;
using namespace System::Runtime::InteropServices;

// a native class
class PlantData
{
   private:

   wchar_t* family;
   wchar_t* genus;
   wchar_t* species;

   public:

   PlantData(const wchar_t* botanical_name)
   {
       // Let's assume this method
       // populates its
       // fields with data from the database
   }

};

// The following managed class contains a pointer to a native class.

ref class TreeSpecies
{
   PlantData* treedata;

   public:
     TreeSpecies(String^ genus, String^ species)
     {
         String^ botanical_name = gcnew String(genus + " " + species);

         // use the Marshal class to create a pointer.
         // The managed class corresponding to a
         // pointer is IntPtr.
         IntPtr ip = Marshal::StringToHGlobalAnsi(botanical_name);

         // Cast that to the appropriate pointer type.
         const wchar_t* str = static_cast<const wchar_t*>(ip.ToPointer());
         treedata = new PlantData(str);
         Marshal::FreeHGlobal( ip );

     }

     ~TreeSpecies() { this->!TreeSpecies(); }
     !TreeSpecies() { if (treedata) delete treedata; }
};
