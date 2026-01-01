# Reset VS Code and Docker Desktop

If you need to restore your computer to the state where you had just freshly installed `VS Code` or `Docker Desktop`, follow the information below:

### **WARNING:** You will lose settings, but most likely will not lose user data.

- You can choose to only reset `VS Code` or `Docker Desktop`. There is no need to do both.

## 1. How to reset VS Code installation data:

This removes all the settings, extensions, history. It restores VS Code to a "just freshly installed" state.

#### Make sure `VS Code` is not running:

**macOS:**

- Copy and paste into `terminal`:

  ```zsh
  rm -rf ~/Library/Application\ Support/Code ~/.vscode
  ```

**Windows (PowerShell):**

- Copy and paste into `Powershell`:

  ```powershell
  Remove-Item -Recurse -Force "$env:APPDATA\Code", "$env:USERPROFILE\.vscode"
  ```

**Done!**

---

## 2. How to reset Docker Desktop

#### Make sure `VS Code` is not running.
#### Make sure `Docker Desktop` *is* running.

**macOS and Windows:** Open `terminal` (macOS) or `PowerShell` (Windows):

- **Stop all running containers:** copy and paste into the prompt:

  ```
  docker stop $(docker ps -q)
  ```

  It will print something. You can ignore the output.

- **Remove all images:** copy and paste into the prompt:

  ```
  docker system prune -a -f
  ```

  It will eventually print out:

  > `Total reclaimed space: x.xxGB`

**Done!**
