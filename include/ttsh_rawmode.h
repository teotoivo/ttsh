#ifndef TTSH_RAWMODE_H
#define TTSH_RAWMODE_H

/**
 * disables terminal raw mode
 */
void disableRawMode();

/**
 * enables terminal raw mode
 */
void enableRawMode();

extern struct termios orig_termios;
#endif // !TTSH_RAWMODE_H
