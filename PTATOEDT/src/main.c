#include <ti/getcsc.h>
#include <graphx.h>
#include <fileioc.h>
#include <fontlibc.h>

int main(void)
{
    char *test_str = "Hello, world! This is a much longer test string!\n";
    char *font_pack_name = "DRSANS";
    fontlib_font_t *font_pack;

    /* Initialize graphics drawing */
    gfx_Begin();

    /* Erase the screen to black */
    gfx_ZeroScreen();

    fontlib_SetWindowFullScreen();
    fontlib_SetCursorPosition(1, 1);
    fontlib_SetColors(0xC0, 0x20);
    fontlib_SetTransparency(true);
    fontlib_SetNewlineOptions(FONTLIB_ENABLE_AUTO_WRAP);
    gfx_SetTextFGColor(0xC0);
    gfx_SetTextBGColor(0x20);

    /* Set a font to use. */
    font_pack = fontlib_GetFontByIndex(font_pack_name, 1);
    if (font_pack) {
        fontlib_SetFont(font_pack, 0);
        fontlib_DrawString(test_str);
    }
    else
    {
        gfx_PrintStringXY("1 not found", 0, 200);
    }

    /* Waits for a key */
    while (!os_GetCSC());

    /* End graphics drawing */
    gfx_End();

    return 0;
}
