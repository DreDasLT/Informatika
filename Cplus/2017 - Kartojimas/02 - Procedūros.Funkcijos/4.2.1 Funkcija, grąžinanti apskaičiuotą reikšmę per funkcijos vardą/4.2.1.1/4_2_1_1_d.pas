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
   var  a, b, c : integer;    // traukinio i�vykimo diena, valanda, minut�
           d, e : integer;   // kelion�s trukm� valandomis ir minut�mis
       ds, v, m : integer;   // susitikimo prad�ios laikas: diena, valanda, minut�
         t1, t2 : longint;  // atvykimo ir susitikimo laikas minut�mis
     da, va, ma : integer;  // atvykimo laikas: diena, valanda, minut�
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

