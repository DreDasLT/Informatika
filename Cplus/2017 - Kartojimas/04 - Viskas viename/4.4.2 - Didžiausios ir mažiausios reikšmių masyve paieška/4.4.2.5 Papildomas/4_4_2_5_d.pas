program Mokymasis;
  const  duom = 'Duomenys.txt';
  const  rez = 'Rezultatai.txt';
  type Masyvas1 = array[1..50] of integer;
//-------------------------------------------------
procedure Skaitymas(var ZP, ZI : Masyvas1);
   var             i : integer; n, z1, z2, d : integer;
                  fd : text;
begin
  Assign (fd, duom);
  Reset (fd);
  ReadLn (fd, n);
  for i := 1 to 31 do
    begin
       ZP[i] := 0;
       ZI[i] := 0;
    end;
  for i := 1 to n do
    begin
      ReadLn (fd, z1, z2, d);
      ZP[d] := z1; ZI[d] := z2;
    end;
  Close (fd);
end;
//-------------------------------------------------
function Didziausias(X : Masyvas1; n : integer) : integer;
   var i, m : integer;
begin
   m := 1;
   while (X[m] = 0) do m := m + 1;
   for i := 1 to n do
     if X[i] > X[m] then m := i;
   Didziausias := m;
end;
//-------------------------------------------------
function Maziausias(X : Masyvas1; n : integer) : integer;
   var i, m : integer;
begin
   m := 1;
   while (X[m] = 0) do m := m + 1;
   for i := 1 to n do
     if (X[i] <> 0) and (X[i] < X[m]) then m := i;
   Maziausias := m;
end;
//-------------------------------------------------
procedure Rasymas(ZP, ZI : Masyvas1);
   var fr : text; i, mm : integer;
begin
  Assign (fr, rez);
  Rewrite (fr);
  mm := Didziausias(ZI, 31);
  Write (fr, ZI[mm], ' ');
  for i := 1 to 31 do
    if ZI[i] = ZI[mm] then Write (fr, i, ' ');
  WriteLn (fr);
  mm := Maziausias(ZP, 31);
  Write (fr, ZP[mm], ' ');
  for i := 1 to 31 do
    if ZP[i] = ZP[mm] then Write (fr, i, ' ');
  WriteLn (fr);
  Close (fr);
end;
//-------------------------------------------------
   var ZI, ZP : Masyvas1;
begin
  Skaitymas(ZP, ZI);
  Rasymas(ZP, ZI);
end.
