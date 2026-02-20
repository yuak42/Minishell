[TR]

### Markdown dosyasını okumak için talimatlar

Daha iyi görmek için 
1. Markdown Preview Enhanced extension indir
2. Bu dosyda ctrl + shift + v bas
3. Preview dosyasını tutup sağa koyabilirsin editlerken.

# Görev Dağılımı

## Parser (Input Handler)

- Tek tırnak ' (single quote)
- Çift tırnak " (double quote)


### Redirections

- inputu ilet < (redirect input)
- outputu ilet > (redirect output)

- "<<"
- ">>"

- pipe |


## Executer (System Execution)

- Subjectte belirtilen komutlar

## Ortak Sorumluluklar

- Memory leak
- Environment değişkenleri
- Sinyaller


# Nasıl Çalışacağız?

1. Projeye başlamadan önce her zaman:
```sh
git pull
```
2. Yeni bir özellik geliştiriyorsak onun branch'ini açmalıyız:
```sh
git branch new-feature
git checkout new-feature
# ya da iki komutu aynı anda
git checkout -b new-feature
```
3. Nerede olduğumuzu kontrol etmeliyiz:
```sh
git log
git status
```