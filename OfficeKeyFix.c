#include <windows.h>

int main(void) {
  // Array of keys to unregister
  // These map to W, T, Y, O, P, D, L, X, N, Space and finally the modifier itself
  UINT offendingKeys[11] = {0x57, 0x54, 0x59, 0x4F, 0x50, 0x44, 0x4C, 0x58, 0x4E, 0x20, 0x0};

  // Kill Explorer
  system("taskkill /IM explorer.exe /F");

  // Register hotkey
  for (int i = 0; i < 11; i++) {
    RegisterHotKey(NULL, i, 0x1 + 0x2 + 0x4 + 0x8 | MOD_NOREPEAT, offendingKeys[i]);
  }

  // Restart Explorer
  system("start explorer.exe");

  /* Sleep for a few seconds to make sure Explorer has time to
     attempt to register the Office hotkeys, and get blocked by
     our hotkeys */
  Sleep(4000);

  // Deregister hotkeys by ID
  for (int i = 0; i < 11; i++) {
    UnregisterHotKey(NULL, i);
  }

  return 0;
}