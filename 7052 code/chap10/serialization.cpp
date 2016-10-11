// serialization.cpp
#using "System.Xml.dll"

using namespace System;
using namespace System::IO;
using namespace System::Xml::Serialization;

// To participate in serialization, types must be public.
[Serializable]
public enum class SunEnum { FullSun, PartShade, Shade };

[Serializable]
public enum class WaterEnum { Moist, Medium, Dry };

[ Serializable]
public ref class Plant
{
    // an internal counter to determine instance IDs
    static int counter;


   // The instance ID keeps track of the plant objects. It will be
   // a different ID when the object is deserialized, so this does not need
   // to be serialized. We use the NonSerialized attribute to indicate that.
   [NonSerialized]
    int InstanceID;

   public:
   property String^ Genus;
   property String^ Species;
   property String^ Cultivar;
   property String^ CommonName;
   property SunEnum Sun;
   property WaterEnum Water;
   property int Zone;



   Plant() {}

   Plant(String^ genus, String^ species, String^ commonName,
         String^ cultivar, SunEnum sun, WaterEnum water, int zone)
   {
       Genus = genus; Species = species; Cultivar = cultivar;
       Sun = sun; Water = water; Zone = zone;
       InstanceID = counter++;
   }

   static Plant() { counter = 0; }

};

void CreateAndSerialize(String^ genus, String^ species, String^ commonName,
         String^ cultivar, SunEnum sun, WaterEnum water, int zone)
{
    Plant^ p = gcnew Plant(genus, species, commonName, cultivar, sun,
                    water, zone);

    // The XmlSerializer takes the Type object as a parameter.
    XmlSerializer^ serializer = gcnew XmlSerializer(Plant::typeid);
    // Create a StreamWriter object to write to a file.
    StreamWriter^ sw = gcnew StreamWriter("plants.xml");

    // Serialize causes the XML to be generated.
    serializer->Serialize(sw, p);
    sw->Close();
}

Plant^ Deserialize()
{
   Plant^ p;
   XmlSerializer^ serializer = gcnew XmlSerializer(Plant::typeid);
   // To read the file, use a FileStream object.
   FileStream^ fs = gcnew FileStream("plants.xml", FileMode::Open);
   // Deserialize and cast to object type.
   p = safe_cast<Plant^>( serializer->Deserialize(fs) );
   return p;
}

int main()
{
   CreateAndSerialize("Ampelopsis", "brevipedunculata",
        "Porcelain Berry", nullptr, SunEnum::PartShade, WaterEnum::Medium,
        4);

   Deserialize();
}
