program Kelione;
   const  duom = 'Duomenys.txt';
   const  rez = 'Rezultatai.txt';
//-------------------------------------------------
function Bilietai (n : integer; b : real) : real;
   begin
      Bilietai := n * b;
   end;
//-------------------------------------------------
   var        k : real;        // kuro sànaudos 100 km
              n : integer;     // ðeimos nariø skaièius
              m : real;        // marðruto ilgis km
             kk : real;       // kuro litro kaina
              b : real;       // bilieto kaina vykstant visuomeniniu transportu
              a : integer;    // autobusø, vykstanèiø pasirinktu marðrutu, skaièius
              s : real;        // iðlaidos vykstant nuosavu transportu
              i : integer;
         fd, fr : text;
begin
  Assign (fd, duom);
  Reset (fd);
  Assign (fr, rez);
  Rewrite (fr);
  Readln (fd, k, m, kk, n);
  ReadLn (fd, a);
  s := (m / 100) * k * kk;
  for i := 1 to a do
     begin
        ReadLn (fd, b);
        WriteLn (fr, s - Bilietai(n, b):0:2);
     end;
  Close(fd);
  Close (fr);
end.

