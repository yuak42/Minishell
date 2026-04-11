Yeni bir özellik yapacak ya da dosya yazacaksan

### 1. Üzerinde çalışacağın özellik için branch aç

Branch isminin eşsiz olduğundan emin ol. Örnek olarak,
```sh
git branch -a
```
komutu ile tüm branch'lere önce bir bak. Sonra kendi branch'ini *düzgün* bir isimle aç.

#### 1.1 Branch aç

```sh
git branch <yeni-branch-ismi>
```

#### 1.2 Branch'ine git

```sh
git checkout <yeni-branch-ismi>
```

### 2. Hangi klasörde hangi isimlerde dosya açacaksın belirle

İstersen önce ayrı bir klasör açıp onun üzerinde testler yapabilirsin.
Mesela built_in klasörüne ft_exit.c ekleyeceksin diyelim.
built_in içerisinde exit diye bir klasör açıp onun içerisinde kodunu yazabilirsin.
veya ft_exit.c diye dosya açıp onun içinde de çalışabilirsin.

Ana yapıyı bozmamak adına ayrı bir klasör içinde çalışıp sonra kodunu test ettikten sonra
normal yerine koymanı tercih ederim.

!! Kodunu test ederken başka dosyaların değişmesi gerekirse benden şu dosyaların şu şekilde güncellenmesi gerek şeklinde istekte bulunabilirsin. Mutlaka iletişimde kalalım.


### 3. Hangi dosyaları oluşturduysan onları .mk dosyana yaz
Örnek olarak, diyelim ft_exit.c dosyasını test edeceksin sıfırdan yazdın.

```mk
#byaprak.mk (project klasörünün hemen içinde)
BYAPRAK_SRC = src/built_in/ft_exit.c 
```
Temel makefile içerisinde şöyle bir satır olacak.

```makefile
include byaprak.mk
SRC += BYAPRAK_SRC
```

Böylece bu dosya sayesinde senin kaynak dosyaların ana projeye dahil olacak. Projenin çalıştığından emin olunca da birlikte test ederek temel makefile içersinde asıl SRC değişkeninin değerini güncelleriz.

İlla temel Makefile güncellemen gerekiyorsa mutlaka birlikte karar vermemiz gerekiyor.

### 4. Çalışmanı Kendi Branch'ine pushla !!!

```sh
git push origin <branch-ismi>
```