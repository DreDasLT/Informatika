program korteles;
  const  duom = 'Duomenys.txt';
  const  rez = 'Rezultatai.txt';
  type Masyvas1 = array[0..20] of integer;
//-------------------------------------------------
function Kiekis(x : integer; y : integer) : integer;
begin
  Kiekis := x - y;
end;
//-------------------------------------------------
procedure Skaitymas(var S : Masyvas1);
   var           i : integer;
      n, k, nr, kr : integer;
                fd : text;
begin
  Assign (fd, duom);
  Reset (fd);
  ReadLn (fd, k, n);
  for i := 0 to 10 do
    S[i] := n;
  for i := 1 to k do
     begin
       ReadLn (fd, nr, kr);
       S[nr] := Kiekis(S[nr], kr);
     end;
  Close (fd);
end;
//-------------------------------------------------
procedure Rasymas(S : Masyvas1);
   var    i : integer;
         fr : text;
begin
  Assign (fr, rez);
  Rewrite (fr);
  for i := 0 to 10 do
    WriteLn (fr, i, ' ', S[i]);
  Close (fr);
end;

//-------------------------------------------------
   var S : Masyvas1;
begin
  Skaitymas(S);
  Rasymas(S);
end.
