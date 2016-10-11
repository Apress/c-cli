// xml_comments.cpp
// compile with: /LD /clr /doc
// then run: xdcmake xml_comments.xdc

using namespace System;

/// Ref class R demonstrates XML Documentation Comments.
/// <summary> A class demonstrating documentation comments </summary>
/// <remarks> A detailed description of R goes into the remarks block
/// </remarks>
public ref class R
{
public:
   /// <summary>F is a method in the R class.
   /// <para>You can break the comments into paragraphs.
   /// <see cref="R::G"/> for related information.</para>
   /// <seealso cref="R::G"/>
   /// </summary>
   void F(int i) {}

   /// The method G is a method in the R class.
   /// <summary>Counts the number of characters in two strings.</summary>
   /// <param name="s1"> Description for s1</param>
   /// <param name="s2"> Description for s2</param>
   /// <returns>The sum of the length of two strings.</returns>
   int G(String^ s1, String^ s2){ return s1->Length + s2->Length; }
};
