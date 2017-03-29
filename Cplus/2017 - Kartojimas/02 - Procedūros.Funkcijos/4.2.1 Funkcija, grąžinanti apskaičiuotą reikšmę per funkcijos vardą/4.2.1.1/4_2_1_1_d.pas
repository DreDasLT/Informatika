program Susitikimas;
   const  duom = 'Duomenys.txt';
   const  rez = 'Rezultatai.txt';
//-------------------------------------------------
function Tikrinimas (t1, t2 : longint) : boolean;
  begin
    if (t1 <= t2)
      then Tikrinimas := true
      else Tikrinimas := false;
  end;
//-------------------------------------------------
   var  a, b, c : integer;    // traukinio iðvykimo diena, valanda, minutë
           d, e : integer;   // kelionës trukmë valandomis ir minutëmis
       ds, v, m : integer;   // susitikimo pradþios laikas: diena, valanda, minutë
         t1, t2 : longint;  // atvykimo ir susitikimo laikas minutëmis
     da, va, ma : integer;  // atvykimo laikas: diena, valanda, minutë
         fd, fr : text;
begin
  Assign (fd, duom);
  Reset (fd);
  Readln (fd, a, b, c, d, e);
  ReadLn (fd, ds, v, m);
  Close (fd);
  t1 := a * 24 * 60 + b * 60 + c + d * 60 + e;
  t2 := ds * 60 * 24 + v * 60 + m;
  da := t1 div 60 div 24;
  va := t1 div 60 mod 24;
  ma := t1 mod 60;
  Assign (fr, rez);
  Rewrite (fr);
  WriteLn (fr, da, ' ', va, ' ', ma);
  if Tikrinimas(t1, t2)
     then WriteLn (fr, 'TAIP')
     else WriteLn (fr, 'NE');
  Close (fr);
end.

