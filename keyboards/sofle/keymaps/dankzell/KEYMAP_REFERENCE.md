# Sofle Keyboard - DankZell Keymap Reference

This document provides a complete visual reference for all layers and features in the DankZell keymap.

## 🎮 Quick Access Features

### 🔥 Key Combos
- **C + L**: Insert `console.log();` with cursor between parentheses
- **ESC + TAB**: Toggle Gaming Layer (_GAME1)

### ⚡ Tap Dance
- **Shift (left/right) double-tap**: Activate Caps Word mode

### 🎯 Special Keys
- **SFTLLCK** (Right Shift + 0): Tap for layer lock, hold for Right Shift + 0

## 📐 Layer Overview

### 0️⃣ Base Layer (_QWERTY)
The main typing layer with home row mods for efficient typing.

```
,-----------------------------------------.                    ,-----------------------------------------.
|  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
|------+------+------+------+------+------|                    |------+------+------+------+------+------|
| ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   '  |
|------+------+------+------+------+------|                    |------+------+------+------+------+------|
| Tab  |   A  | S/Alt| D/Ctl| F/Sft|   G  |-------.    ,-------|   H  | J/Sft| K/Ctl| L/Alt|   ;  | Bspc |
|------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
|LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |SFTLCK|
`-----------------------------------------/       /     \      \-----------------------------------------'
          | LGUI | LAlt | LCTR |SYMBOL| /ENTER  /       \SPACE \  | NAV  | RCTR | RAlt | RGUI |
          |      |      |      |      |/       /         \      \ |      |      |      |      |
          `----------------------------------'           '------''---------------------------'
```

**Key Features:**
- **Home Row Mods**: S/D/F (left), J/K/L (right) act as Alt/Ctrl/Shift when held
- **Layer Access**: SYMBOL layer (left thumb), NAV/NUM layers (right thumb)
- **Encoder**: Left (volume), Right (unused)

---

### 1️⃣ Sweep QWERTY (_SWEQWERTY)
Alternative base layer (identical to _QWERTY for this keymap).

---

### 2️⃣ Symbols Layer (_SYMBOLS)
All symbols, numbers, and function keys for coding and productivity.

```
,-----------------------------------------.                    ,-----------------------------------------.
|      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
|------+------+------+------+------+------|                    |------+------+------+------+------+------|
|  `   |   1  |   2  |   <  |   >  |   [  |                    |   ]  |   &  |   |  |  `   |  F12 |   '  |
|------+------+------+------+------+------|                    |------+------+------+------+------+------|
|      |  !   |   =  |   -  |   (  |   {  |-------.    ,-------|   }  |   )  |   .  |   #  |   @  |      |
|------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
|      |  %   |   $  |   +  |   _  |      |-------|    |-------|   *  |   ^  |   ;  |   :  |   \  |      |
`-----------------------------------------/       /     \      \-----------------------------------------'
          | LGUI | LAlt | LCTR |SYMBOL| /ENTER  /       \SPACE \  |ADJST | RCTR | RAlt | RGUI |
          |      |      |      |      |/       /         \      \ |      |      |      |      |
          `----------------------------------'           '------''---------------------------'
```

**Key Features:**
- **Function Keys**: F1-F12 on top row
- **Coding Symbols**: Brackets, operators, special characters
- **Access to ADJUST**: Right thumb key accesses system controls

---

### 3️⃣ Navigation Layer (_NAV)
Mouse-like navigation, text editing, and window management.

```
,-----------------------------------------.                    ,-----------------------------------------.
|      |      |      |      |      |      |                    |      |      |      |      |      |      |
|------+------+------+------+------+------|                    |------+------+------+------+------+------|
| Esc  | Ins  | Pscr | Menu |   <  |   >  |                    |FDLine| CLeft|  Up  |CRight| DLine| Bspc |
|------+------+------+------+------+------|                    |------+------+------+------+------+------|
| Tab  |CtlAlt| LAlt | LCtl |LShift|   =  |-------.    ,-------|PgUp  | Left | Down | Right|  Del | Bspc |
|------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
|Shift | Undo |  Cut | Copy | Paste| CAPS |-------|    |-------|PgDn  | Home |      |  End |      |Shift |
`-----------------------------------------/       /     \      \-----------------------------------------'
          | LGUI | LAlt | LCTR |ADJST | /ENTER  /       \SPACE \  | NAV  | RCTR | RAlt | RGUI |
          |      |      |      |      |/       /         \      \ |      |      |      |      |
          `----------------------------------'           '------''---------------------------'
```

**Key Features:**
- **Arrow Keys**: Standard navigation on right side
- **Text Editing**: Cut/Copy/Paste, Undo
- **Word Navigation**: Ctrl+Left/Right for word jumping
- **Line Operations**: Forward/Delete line operations
- **Special**: CtlAlt combo key for complex shortcuts

---

### 4️⃣ Number Layer (_NUM)
Numeric keypad layout for number entry and calculations.

```
,-----------------------------------------.                    ,-----------------------------------------.
|      |      |      |      |      |      |                    |      |      |      |      |      |      |
|------+------+------+------+------+------|                    |------+------+------+------+------+------|
| Esc  |      |      |      |      |      |                    |   +  |   7  |   8  |   9  |   =  |      |
|------+------+------+------+------+------|                    |------+------+------+------+------+------|
| Tab  |      |      |      |      |      |-------.    ,-------|   -  |   4  |   5  |   6  |   .  |      |
|------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
|Shift |      |      |      |      |      |-------|    |-------|   0  |   1  |   2  |   3  |   ,  |      |
`-----------------------------------------/       /     \      \-----------------------------------------'
          | LGUI | LAlt | LCTR |      | /ENTER  /       \SPACE \  | NUM  | RCTR | RAlt | RGUI |
          |      |      |      |      |/       /         \      \ |      |      |      |      |
          `----------------------------------'           '------''---------------------------'
```

**Key Features:**
- **Numeric Keypad**: 0-9 in standard numpad layout
- **Math Operators**: +, -, =, . (decimal)
- **Fast Number Entry**: Optimized for data entry and calculations

---

### 5️⃣ Gaming Layer (_GAME1) 🎮
Optimized for left-handed gaming with all essentials on the right side.

```
,-----------------------------------------.                    ,-----------------------------------------.
|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    | ESC  |   1  |   2  |   3  |   4  |   5  |
|------+------+------+------+------+------|                    |------+------+------+------+------+------|
|  F7  |  F8  |  F9  | F10  | F11  | F12  |                    |   6  |   Q  |   W  |   E  |   R  |   T  |
|------+------+------+------+------+------|                    |------+------+------+------+------+------|
|  Up  | Left | Down |Right | PgUp | PgDn |-------.    ,-------| Tab  |   A  |   S  |   D  |   F  |   G  |
|------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
| LCtl | LAlt | Home | End  | Ins  | Del  |-------|    |-------|LShift|   Z  |   X  |   C  |   V  |   B  |
`-----------------------------------------/       /     \      \-----------------------------------------'
          | LGUI | LAlt | Enter| Space| /ENTER  /       \ SPACE \  |Enter | RCTR | RAlt | RGUI |
          |      |      |      |      |/       /         \      \ |      |      |      |      |
          `----------------------------------'           '------''---------------------------'
```

**Gaming Features:**
- **🎯 All essentials on right side**: WASD, numbers, letters, ESC, Tab, Shift
- **🔧 Function keys**: F1-F12 for game shortcuts and macros
- **🏃 Navigation**: Arrow keys and page up/down on left
- **⌨️ Modifiers**: Easy access to Ctrl, Alt, Shift for complex game commands
- **🎮 Toggle**: Use ESC+TAB combo to enter/exit gaming mode

**Perfect for:**
- FPS games (WASD movement)
- MMORPGs (number keys for hotbars)
- Strategy games (function keys for commands)
- Left-handed gaming setups

---

### 6️⃣ Adjust Layer (_ADJUST)
System controls, RGB lighting, and keyboard configuration.

```
,-----------------------------------------.                    ,-----------------------------------------.
|      |      |      |      |      |      |                    | RGB B| RGB R|RGB SW| RGB K|RGB TW|      |
|------+------+------+------+------+------|                    |------+------+------+------+------+------|
|QKBOOT|      |      |      |      |      |                    |      | R Hu+| R Tog| R Sa+|      |      |
|------+------+------+------+------+------|                    |------+------+------+------+------+------|
|ROMCLR|      | CGTOG|      |      |      |-------.    ,-------|      | VOL- | MUTE | VOL+ |      |      |
|------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
|      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
`-----------------------------------------/       /     \      \-----------------------------------------'
          | LGUI | LAlt | LCTR |LOWER | /ENTER  /       \SPACE \  |RAISE | RCTR | RAlt | RGUI |
          |      |      |      |      |/       /         \      \ |      |      |      |      |
          `----------------------------------'           '------''---------------------------'
```

**System Features:**
- **🔄 Firmware**: QK_BOOT for bootloader, EE_CLR for EEPROM reset
- **🌈 RGB**: Multiple RGB modes and controls
- **🔊 Media**: Volume, play/pause, track controls
- **⚙️ Config**: Command/GUI toggle (CGTOG)

---

## 🎨 RGB Lighting Modes

When RGB is enabled, the ADJUST layer provides access to:
- **RGB_M_B**: Breathing effect
- **RGB_M_R**: Rainbow effect  
- **RGB_M_SW**: Swirl effect
- **RGB_M_K**: Knight effect
- **RGB_M_TW**: Twinkle effect
- **RGB_TOG**: Toggle RGB on/off
- **RGB_HUI/SAI**: Adjust hue/saturation

## 🖥️ OLED Display

The OLED shows:
- **Master Side**: Current layer, caps lock status, active modifiers
- **Slave Side**: "Sofle Keyboard" text

## 🔧 Advanced Features

### Caps Word
- **Activation**: Double-tap either Shift key
- **Behavior**: Capitalizes letters, allows numbers/backspace/delete
- **Deactivation**: Any other key or double-tap Shift again

### Layer Lock
- **SFTLLCK Key**: Tap to lock current layer, hold for Shift+0
- **Usage**: Keeps a layer active without holding the layer key

### Combos
- **Console Log**: Press C+L together for instant `console.log();`
- **Game Toggle**: Press ESC+TAB together to toggle gaming layer

## 🎯 Workflow Tips

### For Coding:
1. Use SYMBOLS layer for brackets and operators
2. C+L combo for quick console logging
3. NAV layer for efficient text navigation
4. Home row mods for modifier access

### For Gaming:
1. ESC+TAB to enter gaming mode
2. All essentials on right side for left-handed play
3. Function keys for game macros
4. Easy modifier access for complex commands

### For General Use:
1. Home row mods for efficient typing
2. NUM layer for numeric data entry
3. NAV layer for document navigation
4. ADJUST for system controls

---

*Created for the Sofle RGB keyboard with QMK firmware*
