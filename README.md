# OfficeKeyFix

Unbinds the [Office Key](https://support.microsoft.com/en-us/topic/using-the-office-key-df8665d3-761b-4a16-84b8-2cfb830e6aff) (Shift+Control+Alt+Win) and its related shortcuts, allowing you to use the key combinations in other applications.

You'll need to compile the script into a binary, and place it in `C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Startup` so it will run on startup.

## Compiling with MSVC

You must link `user32.lib` from Windows 10/11 SDK. The SDK can be obtained as part of [VS Build Tools](https://visualstudio.microsoft.com/visual-cpp-build-tools/).

Using the Developer Command Prompt included with Build Tools:

```sh
cl /O2 .\OfficeKeyFix.c /link user32.lib
```