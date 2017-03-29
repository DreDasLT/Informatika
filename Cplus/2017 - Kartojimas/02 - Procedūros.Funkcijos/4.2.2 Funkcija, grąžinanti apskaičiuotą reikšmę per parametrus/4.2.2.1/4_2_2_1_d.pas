program Marsrutai;
	const  duom = 'Duomenys.txt';
	const  rez = 'Rezultatai.txt';
//-------------------------------------------------
function Trukme1 (vi, mi, va, ma : integer) : longint;
   var t : integer;
begin
   if vi * 60 + mi <= va * 60 + ma
      then t := va * 60 + ma - vi * 60 - mi
      else t := 24 * 60 - vi * 60 - mi + va * 60 + ma;
    Trukme1 := t;
end;
//-------------------------------------------------
procedure Trukme (v1, m1, v2, m2, v3, m3, v4, m4 : integer; var v, m : integer);
   var t : longint;
begin
   if (v3 = 0) and (m3 = 0) and (v4 = 0) and (m4 = 0)
         then t := Trukme1(v1, m1, v2, m2)
         else t := Trukme1(v1, m1, v2, m2) + Trukme1(v3, m3, v4, m4);
   v := t div 60;
   m := t mod 60;
end;
//-------------------------------------------------

   var        n : integer;       // marsrutu skaicius
         v1, m1 : integer;      // pirmojo traukinio isvykimo valanda ir minute
         v2, m2 : integer;      // pirmojo traukinio atvykimo valanda ir minute
         v3, m3 : integer;      // antrojo traukinio isvykimo valanda ir minute
         v4, m4 : integer;      // antrojo traukinio atvykimo valanda ir minute
          v, m  : integer;      // keliones trukme valandos ir minutes
              i : integer;
         fd, fr : text;
begin
  Assign (fd, duom);
  Reset (fd);
  Assign (fr, rez);
  Rewrite (fr);
  ReadLn (fd, n);
  for i := 1 to n do
     begin
        ReadLn (fd, v1, m1, v2, m2, v3, m3, v4, m4);
        Trukme (v1, m1, v2, m2, v3, m3, v4, m4, v, m);
        WriteLn (fr, v, ' ',m);
     end;
  Close(fd);
  Close (fr);
end.