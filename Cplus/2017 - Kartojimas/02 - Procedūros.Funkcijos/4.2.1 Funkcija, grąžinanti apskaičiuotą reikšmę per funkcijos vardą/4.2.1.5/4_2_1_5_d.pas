program Planas;
   const  duom = 'Duomenys.txt';
   const  rez = 'Rezultatai.txt';
//-------------------------------------------------
function Kiekis (a, b : integer) : integer;
   begin
      Kiekis := a - b;
   end;
//-------------------------------------------------
   var           d : integer;            // dien� skai�ius
                  z : integer;          // kiek �od�i� turi i�mokti per dien�
                 dz : integer;         // per dien� i�mokt� �od�i� skai�ius
                 dn : integer;        // kelias dienas nevykdytas planas
                 zn : integer;        // nei�mokt� �od�i� skai�ius
                 dp : integer;        // kelias dienas mokysis papildomai
                  i : integer;
             fd, fr : text;
begin
  dn := 0; zn := 0;
  Assign (fd, duom);
  Reset (fd);
  Readln (fd, d, z);
  for i := 1 to d do
     begin
        Read (fd, dz);
        if (Kiekis(z, dz) > 0) then dn := dn + 1;
        zn := zn + Kiekis(z, dz);
     end;
  Close(fd);
  Assign (fr, rez);
  Rewrite (fr);
  WriteLn (fr, dn);
  WriteLn (fr, zn);
  if (zn mod z = 0) then dp := zn div z
  else dp := zn div z + 1;
  WriteLn (fr, dp);
  Close (fr);
end.

