program Ketvirtokas;
   const  duom = 'Duomenys.txt';
   const  rez = 'Rezultatai.txt';
//-------------------------------------------------
procedure Skaitmenys(var s : integer; k : integer; var kk : integer);
begin
   kk := s div k;
   s := s mod k;
end;
//-------------------------------------------------

   var        s : integer;      // ant korteles uzrasytas skaicius
     k5, k3, k1 : integer;     // sumoje esanciu 5, 3 ir 1 kiekiai
         fd, fr : text;
begin
  Assign (fd, duom);
  Reset (fd);
  Assign (fr, rez);
  Rewrite (fr);
  ReadLn (fd, s);
  Close(fd);
  Skaitmenys (s, 5, k5);
  Skaitmenys (s, 3, k3);
  k1 := s;
  WriteLn (fr, 5, ' ', k5);
  WriteLn (fr, 3, ' ', k3);
  WriteLn (fr, 1, ' ', k1);
  Close (fr);
end.
