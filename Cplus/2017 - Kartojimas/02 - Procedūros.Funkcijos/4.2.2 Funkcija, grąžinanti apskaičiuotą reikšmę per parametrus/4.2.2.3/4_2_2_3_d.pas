program Energija;
   const  duom = 'Duomenys.txt';
   const  rez = 'Rezultatai.txt';
//-------------------------------------------------
procedure Produktas (rv, bv, av, r, b, a, p : real; var er, eb, ea : real);
begin
   er := (p / 100) * r * rv;
   eb := (p / 100) * b * bv;
   ea := (p / 100) * a * av;
end;
//-------------------------------------------------

   var        n : integer;    // produktu skaicius
     rv, bv, av : real;      // viename grame riebalu, baltymu ir angliavandeniu esantys kcal kiekiai
        r, b, a : real;     // produkto 100 gramu esantys riebalu, baltymu ir angliavandeniu kiekiai gramais
              p : real;    // produkto kiekis gramais, reikalingas gaminant pateikala
     er, eb, ea : real;   // riebalu, baltymu ir angliavandeniu energetine verte kcal
             pp : real;   // pagaminto patiekalo energetine verte kcal
              i : integer;
         fd, fr : text;
begin
  Assign (fd, duom);
  Reset (fd);
  Assign (fr, rez);
  Rewrite (fr);
  ReadLn (fd, rv, bv, av);
  ReadLn (fd, n);
  pp := 0;
  for i := 1 to n do
     begin
        ReadLn (fd, r, b, a, p);
        Produktas (rv, bv, av, r, b, a, p, er, eb, ea);
        WriteLn (fr, er:0:2, ' ', eb:0:2, ' ', ea:0:2);
        pp := pp + er + eb + ea;
     end;
  WriteLn (fr, pp:0:2);
  Close(fd);
  Close (fr);
end.
