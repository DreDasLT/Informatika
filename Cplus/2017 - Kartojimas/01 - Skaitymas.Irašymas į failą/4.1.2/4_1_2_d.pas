program Automobilis;
   const  duom = 'Duomenys.txt';
   const  rez = 'Rezultatai.txt';
   var  k, m, kk : real;     // automobilio sunaudojamas kuro kiekis 100 km,
                             // kelionës ilgis km, 1 litro kuro kaina
               n : integer;  // keliautojø skaièius
               s : real;     // vieno þmogaus kelionës kaina
          fd, fr : text;
begin
  Assign (fd, duom);
  Reset (fd);
  Readln (fd, k, m, kk, n);
  Close (fd);
  s := ((m / 100) * k) * kk / n;
  Assign (fr, rez);
  Rewrite (fr);
  WriteLn (fr, s : 0 : 1);
  Close (fr);
end.

