# Orbits

A small Game Boy Advance project built with the **Butano** engine.  
You control a moving “center” object, and can spawn orbiters that move using a spring-like force toward the center. This project was completed as an exercise in **refactoring C++ code into header/source files**.

## Live Demo (GitHub Pages)

Play it here: **https://<pdunmire-pcd>.github.io/<orbits>/**

> Tip: If your repo name is `orbits`, the link is usually:
> `https://github.com/pdunmire-pcd/orbits.git`

## Gameplay GIF

![Orbits gameplay](assets/orbits.gif)

> Put your GIF at: `assets/orbits.gif` (or update the path above to match your file)

## Controls (mGBA keyboard defaults)

- **Arrow keys**: move the center
- **X** (A): spawn a new orbiter
- **Z** (B): remove the most recent orbiter

**Extension feature (implemented): adjustable spawn + initial velocity**
- Hold **A** (L) + Arrow keys: move the spawn position (preview dot shows where the next orbiter will appear)
- Hold **S** (R) + Arrow keys: adjust the initial velocity of newly spawned orbiters

> If your controls differ, check your emulator key bindings (mGBA: Tools → Settings → Keyboard → Game Boy Advance).

## What I changed (Refactor work)

- Refactored `dPadMoveSprite` into:
  - `include/movement.h`
  - `src/movement.cpp`
- Refactored `Center` into:
  - `include/Center.h`
  - `src/Center.cpp`
- Refactored `Orbiter` into:
  - `include/Orbiter.h`
  - `src/Orbiter.cpp`
