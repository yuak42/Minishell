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
⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️
1. Projeye başlamadan önce her zaman (herhangi bir değişiklik yapmadan):
- ya sadece 
```sh
git pull
```
- ya da unutup değişiklik yaptıysak
```sh
git checkout main
git pull --rebase origin main
```
2. Yeni bir özellik geliştiriyorsak onun branch'ini açmalıyız: ⚠️⚠️
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

4. En son bir özellikten eminsek onu merge edeceğiz. Bunu birlikte onaylayarak yaparız.
```sh
git merge new-feature # main branchteysen
```

# Commit Mesajları

```sh
git commit -m "kısa"
git commit #uzun mesajlar için
```

`feat` → yeni özellik
`fix` → bug fix
`refactor` → davranış değişmeden kod temizleme
`docs` → README / markdown
`test` → test ekleme

`<type>: <kısa açıklama>`

### Son commit mesajımı nasıl değiştiririm?

```sh
git commit --amend
git push --force-with-lease

```

### Kısa Örnekler:

`feat: Add input handling`
`fix: Handle ctrl-d signal`
`fix: Prevent crash on empty input`
`feat: Support double quotes`
`feat: Implement basic pipe`
`fix: Ignore ctrl-c in parent`
`refactor: Organize main file`

### Uzun Örnekler
```
feat: Add support for quotes and env expansion

- Handle single and double quotes
- Expand environment variables in double quotes
- Prevent token split inside quoted strings
- Add basic syntax error checks
```


```
exec: Implement pipe execution logic

- Create pipes between consecutive commands
- Redirect stdin/stdout using dup2
- Close unused file descriptors
- Wait for child processes correctly
```

### Önemli notlar

- Nasıl yaptığını değil, ne yaptığını söyle.

## Branch İsimleri

Örnek olarak:
- feat-prompt
- feat-execute
- fix-prompt