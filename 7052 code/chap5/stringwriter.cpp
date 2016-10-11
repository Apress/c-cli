// stringwriter.cpp

// The Windows Forms namespace lives in a different
// assembly, which is not referenced by default as is
// mscorlib.dll, so we must use #using here
#using "System.Windows.Forms.dll"

using namespace System;
using namespace System::IO;
using namespace System::Text;
using namespace System::Windows::Forms;

int main()
{
   StringWriter^ sw = gcnew StringWriter();
   sw->WriteLine("Pike Place");
   sw->WriteLine("Street of Dreams");
   sw->WriteLine("(C) 2006 Jeni Hogenson");
   sw->WriteLine();

   sw->Write("Walking with bare feet\n");
   sw->Write("Seattle streets, gospel beat,\n");
   sw->Write("She's got magic\n");
   sw->WriteLine();

   sw->WriteLine("Bag of black upon her back\n" +
                 "A sensual blend, soul food that is;\n" +
                 "Local color.");
   sw->WriteLine();

   String^ jambo = "jambo";
   String^ s = String::Format("Open the bag, {0}, {1}.", jambo, jambo);
   sw->WriteLine(s);
   sw->Write("Make a wish, {0}, {0}.", jambo);
   sw->WriteLine();

   s = "Feel it, grab it, grope it.\n";
   String::Concat(s, "Follow every curve.\n");
   String::Concat(s, "Can you wait to find it?\n");
   String::Concat(s, "Do you have the nerve?");
   sw->WriteLine(s);

   sw->WriteLine("A drop of oil, jambo, jambo.");
   sw->WriteLine("Whisper in her ear,");
   sw->WriteLine("Ask the question in your heart");
   sw->WriteLine("that only you can hear");
   sw->WriteLine();

   StringBuilder^ sb = gcnew StringBuilder();
   sb->Append("Fingers now upon your ears,\n");
   sb->Append("Waiting for the space\n");
   sb->Append("An answer if you're ready now\n");
   sb->Append("From the marketplace\n");
   sw->WriteLine(sb);

   sw->WriteLine("The call of a bird, jambo, jambo.");
   sw->WriteLine("The scent of a market flower,");
   sw->WriteLine("Open wide to all of it and");
   sw->WriteLine("Welcome back your power");
   sw->WriteLine();

   sw->WriteLine("Jambo this and jambo that,");
   sw->WriteLine("Walking with bare feet.");
   sw->WriteLine("No parking allowed when down under,");
   sw->WriteLine("Keep it to the street.");
   sw->WriteLine();

   sw->WriteLine("Dead people rising,");
   sw->WriteLine("Walking with bare feet,");
   sw->WriteLine("No parking allowed when down under,");
   sw->WriteLine("Keep it to the street.");

   // The resulting string might be displayed to the user in a GUI
   MessageBox::Show(sw->ToString(), "Poetry", MessageBoxButtons::OK);
}
