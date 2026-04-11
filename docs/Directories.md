Bu dosya, klasör yapısının daha iyi anlaşılması için yazıldı.

Minishell
|
|--- docs --------> proje ile ilgili tüm dokümanlar burada
|--- project ---------> projede 42 intraya koyacağımız her kaynak dosya burada
		|--- include --------> minishell ile ilgili header dosyalarını buraya koyacağız
		|--- libft ---------> byaprak libft (bunu kendi başına ayrı bir kütüphane olarak koyuyoruz)
		|--- src --------> proje ile ilgili tüm .c dosyaları burada
				|--- built_in ---------> built-in komutların bulunduğu dosya
				|--- prompt	---------> şuanlık basit prompt işlemi için (geçici)
				|--- main.c --------> main fonksiyonunun olduğu kaynak dosya
		|--- Makefile -------> temel makefile

