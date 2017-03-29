program Islaidos;
   const  duom = 'Duomenys.txt';
   const  rez = 'Rezultatai.txt';
//-------------------------------------------------
procedure Kaina(b, d, m, bk, dk : real; var kb, kd : real);
begin
   kb := ((m / 100) * b) * bk;
   kd := ((m / 100) * d) * dk;
end;
//-------------------------------------------------

   var        n : integer;    // degalini� skai�ius
        b, d, m : real;      // benzino, duj� s�naudos 100 km, kelion�s ilgis km
         bk, dk : real;      // benzino ir duj� litro kaina
         kb, kd : real;      // kelion�s kaina, kai automobilis varomas benzinu ir dujomis
              i : integer;
         fd, fr : text;
begin
  Assign (fd, duom);
  Reset (fd);
  Assign (fr, rez);
  Rewrite (fr);
  ReadLn (fd, b, d, m, n);
  for i := 1 to n do
     begin
        ReadLn (fd, bk, dk);
        Kaina (b, d, m, bk, dk, kb, kd);
        WriteLn (fr, kb:0:2, ' ', kd:0:2);
     end;
  Close(fd);
  Close (fr);
end.
