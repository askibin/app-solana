#pragma once

#include <stdint.h>
#include <stddef.h>

#define PUBKEY_SIZE 32
#define BLOCKHASH_SIZE PUBKEY_SIZE

typedef struct Parser {
    uint8_t* buffer;
    size_t buffer_length;
} Parser;

typedef struct Pubkey {
    uint8_t data[PUBKEY_SIZE];
} Pubkey;

typedef struct Blockhash {
    uint8_t data[BLOCKHASH_SIZE];
} Blockhash;

typedef struct Instruction {
    uint8_t program_id_index;
    uint8_t* accounts;
    size_t accounts_length;
    uint8_t* data;
    size_t data_length;
} Instruction;

typedef struct MessageHeader {
    uint8_t num_required_signatures;
    uint8_t num_readonly_signed_accounts;
    uint8_t num_readonly_unsigned_accounts;
} MessageHeader;

int parse_length(Parser* parser, size_t* value);

int parse_message_header(Parser* parser, MessageHeader* header);

int parse_pubkeys(Parser* parser, Pubkey** pubkeys, size_t* pubkeys_length);

int parse_blockhash(Parser* parser, Blockhash** blockhash);

int parse_instruction(Parser* parser, Instruction* instruction);