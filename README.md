# Qt UDP Script Editor & Runner

Два Qt‑приложения обмениваются скриптами по UDP: редактор (`ScriptEditor`) и исполнитель (`ScriptRunner`). Код организован тремя библиотеками/подпроектами (`core`, `network`, `config`) и двумя UI‑приложениями.


## Сборка

### Сборка в Visual Studio 2019

Проект содержит **два отдельных проекта** для Visual Studio 2019, как требуется в задании:

1. **Установка зависимостей:**
   - Установите Visual Studio 2019 с компонентами: Desktop development with C++
   - Установите Qt 5.15 для MSVC2019 64-bit
   - Установите расширение Qt VS Tools для Visual Studio 2019 (через Extensions -> Manage Extensions)

2. **Настройка Qt в Visual Studio:**
   - Откройте Visual Studio 2019
   - Перейдите в Extensions -> Qt VS Tools -> Qt Options
   - Добавьте путь к установленному Qt 5.15 (например, `C:\Qt\5.15.0\msvc2019_64`)
   - Установите эту версию как Default

3. **Откройте проект:**
   - **Вариант 1 (рекомендуется):** Откройте `ScriptEditor\ScriptEditor.sln` — проект редактора скриптов
   - **Вариант 2:** Откройте `ScriptRunner\ScriptRunner.sln` — проект исполнителя скриптов
   - **Вариант 3:** Откройте `qt_udp_scripts.sln` — общий Solution со всеми проектами

4. **Сборка:**
   - Выберите конфигурацию: Debug или Release
   - Выберите платформу: x64
   - Выполните Build -> Build Solution (или `Ctrl+Shift+B`)
   - В результате в папках `x64\Debug\` или `x64\Release\` появятся:
     - `core\core.lib`
     - `network\network.lib`
     - `ScriptEditor\ScriptEditor.exe`
     - `ScriptRunner\ScriptRunner.exe`

5. **Настройка переменной окружения (если требуется):**
   - Добавьте переменную окружения `QTDIR`, указывающую на путь к Qt (например, `C:\Qt\5.15.0\msvc2019_64`)
   - Или настройте в свойствах проекта через Qt VS Tools

### Сборка через Qt Creator (альтернативный способ)

1. Откройте `qt_udp_scripts.pro` в Qt Creator **или** запустите Qt 5.15 MSVC командную строку.
2. Выберите Release (или Debug) и выполните `qmake && nmake` (либо `Ctrl+B` в Qt Creator).
3. В результате появятся:
   - `core/libcore.lib`
   - `network/libnetwork.lib`
   - `ScriptEditor/Release/ScriptEditor.exe`
   - `ScriptRunner/Release/ScriptRunner.exe`

### Важно

Файл `config/profiles.json` должен лежать рядом с бинарями или в папке `config` — его автоматически подхватит `ProfileManager`.

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
