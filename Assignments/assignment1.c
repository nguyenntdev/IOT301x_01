#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define PI 3.14159265
#define sep "\n------------------------------------\n\n"
#define toado "Xin vui long nhap toa do diem"
float ax, ay, bx, by, cx, cy, a, b, c, A, B, C, p, dca, dcb, dcc, g, h;
float tt[3];
void duongcao_tamgiac()
{
  p = (a + b + c) / 2.0;
  dca = ((2 * (sqrt(p * (p - a) * (p - b) * (p - c)))) / a);
  dcb = ((2 * (sqrt(p * (p - a) * (p - b) * (p - c)))) / b);
  dcc = ((2 * (sqrt(p * (p - a) * (p - b) * (p - c)))) / c);
  printf(sep);
  printf("Duong cao dinh A la %.2f \n", dca);
  printf("Duong cao dinh B la %.2f \n", dcb);
  printf("Duong cao dinh C la %.2f \n", dcc);
  printf(sep);
}
void dientich_tamgiac()
{
  p = (a + b + c) / 2.0;
  float s = sqrt(p * (p - a) * (p - b) * (p - c));
  printf(sep);
  printf("Dien tich tam giac la: %.2f \n", s);
}
float tinhcanh(float ax, float ay, float bx, float by)
{
  float a = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
  return a;
}

void loai_tamgiac()
{
  printf(sep);
  if (A > 90)
  {
    printf("Day la tam giac tu tai goc A \n");
  }
  else if (B > 90)
  {
    printf("Day la tam giac tu tai goc B \n");
  }
  else if (C > 90)
  {
    printf("Day la tam giac tu tai goc C \n");
  }
  if (a == b && b == c && a == c)
    printf("Day la tam giac deu \n");
  if (a == b || a == c || b == c)
    printf("Day la tam giac can \n");
  if (A - 90 < 0.000001 && 90 - A < -0.000001)
    printf("Day la tam giac vuong tai goc A \n");
  else if (B - 90 < 0.000001 && 90 - B < -0.000001)
    printf("Day la tam giac vuong tai goc B \n");
  else if (C - 90 < 0.000001 && 90 - C < -0.000001)
    printf("Day la tam giac vuong tai goc C \n");
  if (a < 90 && b < 90 && c < 90 && a != b && b != c && c != a)
    printf("Day la tam giac nhon \n");
}
void ingoc()
{
  float cosA = (b * b + c * c - a * a) / (2 * c * b);
  float cosB = (a * a + c * c - b * b) / (2 * c * a);
  float cosC = (a * a + b * b - c * c) / (2 * a * b);
  A = acos(cosA) * 180 / PI;
  B = acos(cosB) * 180 / PI;
  C = acos(cosC) * 180 / PI;
  printf(sep "So do goc A la %.2f \n", A);
  printf("So do goc B la %.2f \n", B);
  printf("So do goc C la %.2f \n", C);
}

void trungtuyen_tamgiac()
{

  // ma = b(2b2 + 2c2 b  a2)/4
  // mb = b(2a2 + 2c2 b  b2)/4
  // mc = b(2a2 + 2b2 b  c2)/4]
  tt[0] = sqrt((b * b + c * c) / 2 - (a * a) / 4);
  tt[1] = sqrt((a * a + c * c) / 2 - (b * b) / 4);
  tt[2] = sqrt((b * b + a * a) / 2 - (c * c) / 4);
  printf("Do dai trung tuyen tu dinh A la %.2f \n", tt[0]);
  printf("Do dai trung tuyen tu dinh B la %.2f\n", tt[1]);
  printf("Do dai trung tuyen tu dinh C la %.2f\n", tt[2]);
}

void tam_tamgiac()
{
  g = (ax + bx + cx) / 3;
  h = (ay + by + cy) / 3;

  printf(sep);
  printf("Toa do trong tam: [%.2f, %.2f]", g, h);
}

void inketqua()
{
  // In ket qua tu ham tinhcanh
  c = tinhcanh(ax, ay, bx, by);
  a = tinhcanh(bx, by, cx, cy);
  b = tinhcanh(ax, ay, cx, cy);
  // In ket qua tu ham tinhcanh
  printf(sep);
  printf("Chieu dai cua canh AB la %.2f \n", c);
  printf("Chieu dai cua canh BC la %.2f \n", a);
  printf("Chieu dai cua canh AC la %.2f \n", b);
  ingoc();
  loai_tamgiac();
  dientich_tamgiac();
  duongcao_tamgiac();
  trungtuyen_tamgiac();
  tam_tamgiac();
}
int check_tamgiac()
{
  a = tinhcanh(ax, ay, bx, by);
  b = tinhcanh(bx, by, cx, cy);
  c = tinhcanh(ax, ay, cx, cy);
  if (a + b > c && a + c > b && b + c > a)
  {
    return 1;
  }
  return 0;
}
int main()
{
  do
  {
    printf(sep);
    printf(toado " Ax \n");
    scanf("%f", &ax);
    printf(toado " Ay \n");
    scanf("%f", &ay);
    printf(toado " Bx \n");
    scanf("%f", &bx);
    printf(toado " By \n");
    scanf("%f", &by);
    printf(toado " Cx \n");
    scanf("%f", &cx);
    printf(toado " Cy \n");
    scanf("%f", &cy);
    printf(sep);
    printf("Toa do diem A da nhap: A(%.2f; %.2f) \n", ax, ay);
    printf("Toa do diem B da nhap: B(%.2f; %.2f) \n", bx, by);
    printf("Toa do diem A da nhap: c(%.2f; %.2f) \n", cx, cy);
    if (!(check_tamgiac(ax, ay, bx, by, cx, cy)))
    {
      printf(sep "3 toa do tren khong hop thanh 1 tam giac \nXin vui long nhap lai toa do \n");
    }
  } while (!(check_tamgiac(ax, ay, bx, by, cx, cy)));
  printf(sep "Cac toa do da nhap tao thanh 1 tam giac \n");
  inketqua();
}
