#include "../command_registry.h"
#include "../../libs/print.h"

void CMD_uwu(int argc, char** argv) {
    print_str("OwO what's this? :3\n");
}

static const command_t uwu_command = {
    .name = "uwu",
    .short_desc = "Become maximum femboy",
    .usage = "uwu",
    .long_desc = "Prints a cute OwO message to assert dominance.",
    .examples = "uwu",
    .execute = CMD_uwu
};

void CMD_init_uwu() {
    register_command(&uwu_command);
}
