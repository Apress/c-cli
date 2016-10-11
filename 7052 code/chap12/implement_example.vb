' implement_example.vb
' compile with: vbc /r:interface_example.dll implement_example.vb

Public Class VBClass
  Implements ITest

  Public Sub F Implements ITest.F
        Console.WriteLine("F in VB")
  End Sub

  Public Sub G Implements ITest.G
        Console.WriteLine("G in VB")
  End Sub

  Public Shared Sub Main
     Dim Test As ITest = New VBClass
     With Test
        .F()
        .G()
     End With
  End Sub 'Main
End Class 'VBClass
