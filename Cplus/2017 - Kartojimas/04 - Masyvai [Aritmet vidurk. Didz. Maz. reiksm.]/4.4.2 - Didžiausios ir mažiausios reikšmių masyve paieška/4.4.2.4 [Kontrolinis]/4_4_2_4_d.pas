program Darbas;
  const  duom = 'Duomenys.txt';
  const  rez = 'Rezultatai.txt';
  type Masyvas1 = array[0..100] of integer;
//-------------------------------------------------
function Kiekis(x, y : integer) : integer;
  begin
    Kiekis := x - y;
  end;
//-------------------------------------------------
procedure Skaitymas (var KR : Masyvas1);
   var             i : integer; k, n : integer; sk, nr : integer;
                  fd : text;
begin
  Assign (fd, duom);
  Reset (fd);
  ReadLn (fd, n);
  ReadLn (fd, k);
  for i := 0 to 10 do KR[i] := n;
  for i := 1 to k do
     begin
       ReadLn (fd, nr, sk);
       KR[nr] := Kiekis(KR[nr], sk);
       end;
  Close (fd);
end;
//-------------------------------------------------
 function Didziausias(X : Masyvas1; n : integer) : integer;
    var i, m : integer;
begin
   m := 1;
   for i := 1 to n do
     if X[i] > X[m] then m := i;
   Didziausias := m;
end;
//-------------------------------------------------
 function Maziausias(X : Masyvas1; n : integer) : integer;
    var i, m : integer;
begin
   m := 1;
   for i := 1 to n do
     if X[i] < X[m] then m := i;
   Maziausias := m;
end;
//-------------------------------------------------
procedure Rasymas(KR : Masyvas1);
   var fr : text; i, mm : integer;
begin
  Assign (fr, rez);
  Rewrite (fr);
  mm := Didziausias (KR, 10);
  Write (fr, KR[mm], ' ');
  for i := 0 to 10 do
     if KR[i] = KR[mm] then Write (fr, i, ' ');
  WriteLn (fr);
  mm := Maziausias (KR, 10);
  Write (fr, KR[mm], ' ');
  for i := 0 to 10 do
    if KR[i] = KR[mm] then Write (fr, i, ' ');
  WriteLn (fr);
  Close (fr);
end;
//-------------------------------------------------
   var           K : Masyvas1;
begin
  Skaitymas(K);
  Rasymas(K);
end.
