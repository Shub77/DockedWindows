# DockedWindows

This is just a **proof of concept** written in C++ to answer [this StackOverflow question about **Qt** and docked windows](https://stackoverflow.com/questions/7528612/how-to-make-two-side-by-side-qt-windows-sticky-and-act-like-a-single-window/52798335#52798335).

When moved, each window resizes and moves the other via the overridden `moveEvent` method. To avoid endless looping, the window which is moved by the user inhibits the other window's `moveEvent`. This is achieved overriding the `eventFilter` method too, to catch the mouse click that starts the dragging operation. When this happens, a flag in the other window object is set to `true`, thus making its `moveEvent` do nothing. When `eventFilter` catches the left mouse button mouse release (that means the dragging operation is ended), it resets the other window's flag to `false`.
