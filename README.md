# Qt UDP Script Editor & Runner

Два Qt‑приложения обмениваются скриптами по UDP: редактор (`ScriptEditor`) и исполнитель (`ScriptRunner`). Код организован тремя библиотеками/подпроектами (`core`, `network`, `config`) и двумя UI‑приложениями.


## Сборка

1. Откройте `qt_udp_scripts.pro` в Qt Creator **или** запустите Qt 5.15 MSVC командную строку.
2. Выберите Release (или Debug) и выполните `qmake && nmake` (либо `Ctrl+B` в Qt Creator).
3. В результате появятся:
   - `core/libcore.lib`
   - `network/libnetwork.lib`
   - `ScriptEditor/Release/ScriptEditor.exe`
   - `ScriptRunner/Release/ScriptRunner.exe`
4. Файл `config/profiles.json` должен лежать рядом с бинарями или в папке `config` — его автоматически подхватит `ProfileManager`.

## Запуск и проверка

1. Запустите `ScriptEditor.exe` и `ScriptRunner.exe`.
2. В обоих окнах выберите профиль **Localhost** (значения хоста/портов подтянутся автоматически, сокеты перебиндятся).
3. В редакторе нажмите *Insert Example* -> *Send Script*:
   - раннер должен получить текст, в лог попадёт сообщение *Script executed successfully*, холст отрисует фигуры.
4. Для запроса в обратную сторону нажмите в раннере *Request script*.
5. Undo/Redo:
   - редактор: `Ctrl+Z / Ctrl+Y` (либо кнопки в тулбаре).
   - холст: кнопки *Undo Canvas* / *Redo Canvas* в тулбаре раннера.
6. Консольные сообщения из скрипта (`canvas.print(...)`) отображаются в панели *Execution log* плюс пишутся в Qt logging (`script.ui.runner`).

## Логирование

Qt категории:

- `script.ui.editor`
- `script.ui.runner`
- `script.network.transport`

Для просмотра: запустите приложения с переменной `QT_LOGGING_RULES="script.*=true"`.
