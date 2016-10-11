<?xml version="1.0"?>
<doc>
<members>
<member name="T:R" decl="false" source="c:\book\code\appa\xml_comments.cpp" line="7">
Ref class R demonstrates XML Documentation Comments.
<summary> A class demonstrating documentation comments </summary>
<remarks> A detailed description of R goes into the remarks block
</remarks>
</member>
<member name="M:R.F(System.Int32)" decl="false" source="c:\book\code\appa\xml_comments.cpp" line="14">
<summary>F is a method in the R class.
<para>You can break the comments into paragraphs.
<see cref="M:R.G(System.String,System.String)"/> for related information.</para>
<seealso cref="M:R.G(System.String,System.String)"/>
</summary>
</member>
<member name="M:R.G(System.String,System.String)" decl="false" source="c:\book\code\appa\xml_comments.cpp" line="21">
The method G is a method in the R class.
<summary>Counts the number of characters in two strings.</summary>
<param name="s1"> Description for s1</param>
<param name="s2"> Description for s2</param>
<returns>The sum of the length of two strings.</returns>
</member>
</members>
</doc>
