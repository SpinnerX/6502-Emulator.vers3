#pragma once
#include <type_traits>
#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <common/types.h>
#include <cpu/MnemonicTraits.h>


/***
 * 
 * 
 * Operations Types
 * - Reason why we want to access these specicifc Operations based on opcodes is because of the fetch-cycle.
 * - Through the fetch, decode, execute cycle we use opcodes to search which instruction we want to execute.
 * - That is how the cycle process will look to when trying to check which instruction to execute.
 * 
 * 
 * NOTE: (New Note)
 * 
 * Overview
 * After some close thinking on how we want Opcodes to be called during the decoding phase
 * and thinking of specifics regarding the OperationTraits should not know what RegisterTypes are.
 * 
 * New Re-iteration
 * - May take out OperationTypes::<Name> out of OperationTraits because opcodes do not know what reigster 
 *  that these opcodes correspond too (literally)
 * - So, maybe lets refactored the way this works.
 * - Simply by having the following added:
 * Instructions (or just a Registers): class
 * - Contains the RegisterTypes
 * - Contains opcodes for their respective address modes
 * - Using the Operation<opcode_t> class as part of the register
 * - exectute(): which performs the instrucitons
 * 
*/


struct BaseOperation{
    virtual OperationTraits data() = 0;
    AddressModes mode;
    OperationTraits traits;
    InstructionStatus status; // SR Statuses
};


template<auto opcode = 0>
struct Operation;




/**
 * 
 * Load, store, interregister transfer registers
 * 
*/


/**
 * 
 * 
 * LDA
 * -  Immediate
 * - ZeroPage
 * - ZeroPageX
 * - Absolute
 * - Absolute  X
 * - Absolute Y
 * -  Indirect X
 * - Indirect Y
 * 
 * 
*/

template<>
struct Operation<0xA9> : public BaseOperation{
    Operation<0xA9>(){
        traits = OperationTraits(OperationTypes::LDA, AddressModes::IMMEDIATE, 0xA9, 2, 2);
    }

    void execute(opcode_t opcode){
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xA9>& ins){
        return outs << ins.traits;
    }

    OperationTraits data() override{
        return traits;
    }
};

template<>
struct Operation<0xA5> : public BaseOperation{
    Operation<0xA5>(){
        traits = OperationTraits(OperationTypes::LDA, AddressModes::ZPG, 0xA5, 2, 3);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xA5>& ins){
        return outs;
    }
};

template<>
struct Operation<0xB5> : public BaseOperation{
     Operation<0xB5>(){
        traits = OperationTraits(OperationTypes::LDA, AddressModes::ZPG_X, 0xA5, 2, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xB5>& ins){
        return outs;
    }
};


template<>
struct Operation<0xAD> : public BaseOperation{
     Operation<0xAD>(){
        traits = OperationTraits(OperationTypes::LDA, AddressModes::ABS, 0xAD, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xAD>& ins){
        return outs;
    }
};

template<>
struct Operation<0xBD> : public BaseOperation{
     Operation<0xBD>(){
        traits = OperationTraits(OperationTypes::LDA, AddressModes::ABSX, 0xBD, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xBD>& ins){
        return outs;
    }
};

template<>
struct Operation<0xB9> : public BaseOperation{
     Operation<0xB9>(){
        traits = OperationTraits(OperationTypes::LDA, AddressModes::ABSY, 0xB9, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xB9>& ins){
        return outs;
    }
};


template<>
struct Operation<0xA1> : public BaseOperation{
     Operation<0xA1>(){
        traits = OperationTraits(OperationTypes::LDA, AddressModes::INDIRECT_X, 0xA1, 2, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xA1>& ins){
        return outs;
    }
};

template<>
struct Operation<0xB1> : public BaseOperation{
     Operation<0xB1>(){
        traits = OperationTraits(OperationTypes::LDA, AddressModes::INDIRECT_Y, 0xB1, 2, 5);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xB1>& ins){
        return outs;
    }
};

/**
 * 
 * 
 * LDX
 * - Immediate
 * - ZeroPage
 * - ZeroPage Y
 * - Absolute
 * - Absolute Y
 * 
*/


template<>
struct Operation<0xA2> : public BaseOperation{
     Operation<0xA2>(){
        traits = OperationTraits(OperationTypes::LDX, AddressModes::IMMEDIATE, 0xA2, 2, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xA2>& ins){
        return outs;
    }
};

template<>
struct Operation<0xA6> : public BaseOperation{
     Operation<0xA6>(){
        traits = OperationTraits(OperationTypes::LDX, AddressModes::ZPG, 0xA6, 2, 3);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xA6>& ins){
        return outs;
    }
};

template<>
struct Operation<0xB6> : public BaseOperation{
     Operation<0xB6>(){
        traits = OperationTraits(OperationTypes::LDX, AddressModes::ZPG_Y, 0xB6, 2, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xB6>& ins){
        return outs;
    }
};



template<>
struct Operation<0xAE> : public BaseOperation{
     Operation<0xAE>(){
        traits = OperationTraits(OperationTypes::LDX, AddressModes::ABS, 0xAE, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xAE>& ins){
        return outs;
    }
};


template<>
struct Operation<0xBE> : public BaseOperation{
     Operation<0xBE>(){
        traits = OperationTraits(OperationTypes::LDX, AddressModes::ABSY, 0xBE, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xBE>& ins){
        return outs;
    }
};

/**
 * 
 * 
 * LDY (Load Index Y with Memory)
 * - Immediate
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * 
*/

template<>
struct Operation<0xA0> : public BaseOperation{
     Operation<0xA0>(){
        traits = OperationTraits(OperationTypes::LDY, AddressModes::IMMEDIATE, 0xA0, 2, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xA0>& ins){
        return outs;
    }
};

template<>
struct Operation<0xA4> : public BaseOperation{
     Operation<0xA4>(){
        traits = OperationTraits(OperationTypes::LDY, AddressModes::ZPG, 0xA4, 2, 3);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xA4>& ins){
        return outs;
    }
};

template<>
struct Operation<0xB4> : public BaseOperation{
     Operation<0xB4>(){
        traits = OperationTraits(OperationTypes::LDY, AddressModes::ZPG_X, 0xB4, 2, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xB4>& ins){
        return outs;
    }
};


template<>
struct Operation<0xAC> : public BaseOperation{
     Operation<0xAC>(){
        traits = OperationTraits(OperationTypes::LDY, AddressModes::ABS, 0xAC, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xAC>& ins){
        return outs;
    }
};

template<>
struct Operation<0xBC> : public BaseOperation{
     Operation<0xBC>(){
        traits = OperationTraits(OperationTypes::LDY, AddressModes::ABSX, 0xBC, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xBC>& ins){
        return outs;
    }
};






/**
 * 
 * 
 * STA (Store Accumulator in Memory)
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * - Indirect X
 * - Indirect Y
 * 
*/


template<>
struct Operation<0x85> : public BaseOperation{
     Operation<0x85>(){
        traits = OperationTraits(OperationTypes::STA, AddressModes::ZPG, 0x85, 2, 3);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x85>& ins){
        return outs;
    }
};

template<>
struct Operation<0x95> : public BaseOperation{
     Operation<0x95>(){
        traits = OperationTraits(OperationTypes::STA, AddressModes::ZPG_X, 0x95, 2, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x95>& ins){
        return outs;
    }
};


template<>
struct Operation<0x8D> : public BaseOperation{
     Operation<0x8D>(){
        traits = OperationTraits(OperationTypes::STA, AddressModes::ABS, 0x8D, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x8D>& ins){
        return outs;
    }
};

template<>
struct Operation<0x9D> : public BaseOperation{
     Operation<0x9D>(){
        traits = OperationTraits(OperationTypes::STA, AddressModes::ABSX, 0x9D, 3, 5);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x9D>& ins){
        return outs;
    }
};

template<>
struct Operation<0x99> : public BaseOperation{
     Operation<0x99>(){
        traits = OperationTraits(OperationTypes::STA, AddressModes::ABSY, 0x99, 3, 5);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x99>& ins){
        return outs;
    }
};

template<>
struct Operation<0x81> : public BaseOperation{
     Operation<0x81>(){
        traits = OperationTraits(OperationTypes::STA, AddressModes::INDIRECT_X, 0x81, 2, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x81>& ins){
        return outs;
    }
};

template<>
struct Operation<0x91> : public BaseOperation{
     Operation<0x91>(){
        traits = OperationTraits(OperationTypes::STA, AddressModes::INDIRECT_Y, 0x91, 2, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x91>& ins){
        return outs;
    }
};



/**
 * 
 * 
 * STX (Store Index X in Memory)
 * - ZeroPage
 * - ZeroPage Y
 * - Absolute
 * 
*/

template<>
struct Operation<0x86> : public BaseOperation{
     Operation<0x86>(){
        traits = OperationTraits(OperationTypes::STX, AddressModes::ZPG, 0x86, 2, 3);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x86>& ins){
        return outs;
    }
};

template<>
struct Operation<0x96> : public BaseOperation{
     Operation<0x96>(){
        traits = OperationTraits(OperationTypes::STX, AddressModes::ZPG_Y, 0x96, 2, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x96>& ins){
        return outs;
    }
};


template<>
struct Operation<0x8E> : public BaseOperation{
     Operation<0x8E>(){
        traits = OperationTraits(OperationTypes::STX, AddressModes::ABS, 0x8E, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x8E>& ins){
        return outs;
    }
};


/**
 * 
 * 
 * STY (Store Index Y in Memory)
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * 
*/


template<>
struct Operation<0x84> : public BaseOperation{
     Operation<0x84>(){
        traits = OperationTraits(OperationTypes::STY, AddressModes::ZPG, 0x84, 2, 3);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x84>& ins){
        return outs;
    }
};

template<>
struct Operation<0x94> : public BaseOperation{
     Operation<0x94>(){
        traits = OperationTraits(OperationTypes::STY, AddressModes::ZPG_X, 0x94, 2, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x94>& ins){
        return outs;
    }
};

template<>
struct Operation<0x8C> : public BaseOperation{
     Operation<0x8C>(){
        traits = OperationTraits(OperationTypes::STY, AddressModes::ABS, 0x8C, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x8C>& ins){
        return outs;
    }
};

/**
 * 
 * 
 * TAX (Transfer Accumulator to Index X)
 * - IMPLIED
 * 
*/

template<>
struct Operation<0xAA> : public BaseOperation{
     Operation<0xAA>(){
        traits = OperationTraits(OperationTypes::TAX, AddressModes::IMPLIED, 0xAA, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xAA>& ins){
        return outs;
    }
};

/**
 * 
 * 
 * TAY (Transfer Accumulator to Index X)
 * - IMPLIED
 * 
*/

template<>
struct Operation<0xA8> : public BaseOperation{
     Operation<0xA8>(){
        traits = OperationTraits(OperationTypes::TAY, AddressModes::IMPLIED, 0xA8, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xA8>& ins){
        return outs;
    }
};

/**
 * 
 * 
 * TSX (Transfer Stack Ptr to Index X)
 * - IMPLIED
 * 
*/

template<>
struct Operation<0xBA> : public BaseOperation{
     Operation<0xBA>(){
        traits = OperationTraits(OperationTypes::TSX, AddressModes::IMPLIED, 0xBA, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xBA>& ins){
        return outs;
    }
};

/**
 * 
 * 
 * TXA (Transfer Index X to Accumulator)
 * - IMPLIED
 * 
*/

template<>
struct Operation<0x8A> : public BaseOperation{
     Operation<0x8A>(){
        traits = OperationTraits(OperationTypes::TXA, AddressModes::IMPLIED, 0x8A, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x8A>& ins){
        return outs;
    }
};

/**
 * 
 * 
 * TXS (Transfer Index X to Stack Operation)
 * - IMPLIED
 * 
*/

template<>
struct Operation<0x9A> : public BaseOperation{
     Operation<0x9A>(){
        traits = OperationTraits(OperationTypes::TXS, AddressModes::IMPLIED, 0x9A, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x9A>& ins){
        return outs;
    }
};

/**
 * 
 * 
 * TYA (Transfer Index Y to Accumulator)
 * - IMPLIED
 * 
*/

template<>
struct Operation<0x98> : public BaseOperation{
     Operation<0x98>(){
        traits = OperationTraits(OperationTypes::TYA, AddressModes::IMPLIED, 0x98, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x98>& ins){
        return outs;
    }
};


/**
 * 
 * 
 * Stack Instructions
 * 
 * 
 * 
*/


/**
 * 
 * PHA (Push Accumulator on Stack)
 * - IMPLIED
 * 
*/
template<>
struct Operation<0x48> : public BaseOperation{
     Operation<0x48>(){
        traits = OperationTraits(OperationTypes::PHA, AddressModes::IMPLIED, 0x48, 1, 3);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x48>& ins){
        return outs;
    }
};


/**
 * 
 * PHP (Push Processor Status on Stack)
 * - IMPLIED
 * 
*/
template<>
struct Operation<0x08> : public BaseOperation{
     Operation<0x08>(){
        traits = OperationTraits(OperationTypes::PHP, AddressModes::IMPLIED, 0x08, 1, 3);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x08>& ins){
        return outs;
    }
};

/**
 * 
 * PLA (Pull Processor Status from Stack)
 * - IMPLIED
 * 
*/
template<>
struct Operation<0x68> : public BaseOperation{
     Operation<0x68>(){
        traits = OperationTraits(OperationTypes::PLA, AddressModes::IMPLIED, 0x68, 1, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x68>& ins){
        return outs;
    }
};


/**
 * 
 * PLP (Pull Processor Status from Stack)
 * - IMPLIED
 * 
*/
template<>
struct Operation<0x28> : public BaseOperation{
     Operation<0x28>(){
        traits = OperationTraits(OperationTypes::PLP, AddressModes::IMPLIED, 0x28, 1, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x28>& ins){
        return outs;
    }
};




/** Decrement * Increments **/

/**
 * 
 * DEC (Decrement Memory by One)
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * 
*/

template<>
struct Operation<0xC6> : public BaseOperation{
     Operation<0xC6>(){
        traits = OperationTraits(OperationTypes::DEC, AddressModes::ZPG, 0xC6, 2, 5);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xC6>& ins){
        return outs;
    }
};

template<>
struct Operation<0xD6> : public BaseOperation{
     Operation<0xD6>(){
        traits = OperationTraits(OperationTypes::DEC, AddressModes::ZPG_X, 0xD6, 2, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xD6>& ins){
        return outs;
    }
};

template<>
struct Operation<0xCE> : public BaseOperation{
     Operation<0xCE>(){
        traits = OperationTraits(OperationTypes::DEC, AddressModes::ABS, 0xCE, 3, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xCE>& ins){
        return outs;
    }
};

template<>
struct Operation<0xDE> : public BaseOperation{
     Operation<0xDE>(){
        traits = OperationTraits(OperationTypes::DEC, AddressModes::ABSX, 0xDE, 3, 7);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xDE>& ins){
        return outs;
    }
};



/**
 * 
 * DEX (Decrement Index X by One)
 * - IMPLIED
 * 
*/

template<>
struct Operation<0xCA> : public BaseOperation{
     Operation<0xCA>(){
        traits = OperationTraits(OperationTypes::DEX, AddressModes::IMPLIED, 0xCA, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xCA>& ins){
        return outs;
    }
};


/**
 * 
 * DEY (Decrement Index Y by One)
 * - IMPLIED
 * 
*/

template<>
struct Operation<0x88> : public BaseOperation{
     Operation<0x88>(){
        traits = OperationTraits(OperationTypes::DEY, AddressModes::IMPLIED, 0x88, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x88>& ins){
        return outs;
    }
};


/**
 * 
 * INC (Increment Memory By One)
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * 
*/

template<>
struct Operation<0xE6> : public BaseOperation{
     Operation<0xE6>(){
        traits = OperationTraits(OperationTypes::INC, AddressModes::ZPG, 0xE6, 2, 5);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xE6>& ins){
        return outs;
    }
};

template<>
struct Operation<0xF6> : public BaseOperation{
     Operation<0xF6>(){
        traits = OperationTraits(OperationTypes::INC, AddressModes::ZPG_X, 0xF6, 2, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xF6>& ins){
        return outs;
    }
};

template<>
struct Operation<0xEE> : public BaseOperation{
     Operation<0xEE>(){
        traits = OperationTraits(OperationTypes::INC, AddressModes::ABS, 0xEE, 3, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xEE>& ins){
        return outs;
    }
};

template<>
struct Operation<0xFE> : public BaseOperation{
     Operation<0xFE>(){
        traits = OperationTraits(OperationTypes::INC, AddressModes::ABSX, 0xFE, 3, 7);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xFE>& ins){
        return outs;
    }
};



/**
 * 
 * INX (Increment Index X by One)
 * - IMPLIED
 * 
*/

template<>
struct Operation<0xE8> : public BaseOperation{
     Operation<0xE8>(){
        traits = OperationTraits(OperationTypes::INX, AddressModes::IMPLIED, 0xE8, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xE8>& ins){
        return outs;
    }
};


/**
 * 
 * INY (Increment Index Y by One)
 * - IMPLIED
 * 
*/

template<>
struct Operation<0xC8> : public BaseOperation{
     Operation<0xC8>(){
        traits = OperationTraits(OperationTypes::INY, AddressModes::IMPLIED, 0xC8, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xC8>& ins){
        return outs;
    }
};




/**
 * 
 * ADC (Add Memory to Accumulator with Carry)
 * - IMMEDIATE
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * - Absolute Y
 * - Indirect X
 * - Indirect Y
 * 
*/

template<>
struct Operation<0x69> : public BaseOperation{
     Operation<0x69>(){
        traits = OperationTraits(OperationTypes::ADC, AddressModes::IMMEDIATE, 0x69, 2, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x69>& ins){
        return outs;
    }
};

template<>
struct Operation<0x65> : public BaseOperation{
     Operation<0x65>(){
        traits = OperationTraits(OperationTypes::ADC, AddressModes::ZPG, 0x65, 2, 3);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x65>& ins){
        return outs;
    }
};

template<>
struct Operation<0x75> : public BaseOperation{
     Operation<0x75>(){
        traits = OperationTraits(OperationTypes::ADC, AddressModes::ZPG_X, 0x75, 2, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x75>& ins){
        return outs;
    }
};

template<>
struct Operation<0x6D> : public BaseOperation{
     Operation<0x6D>(){
        traits = OperationTraits(OperationTypes::ADC, AddressModes::ABS, 0x6D, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x6D>& ins){
        return outs;
    }
};

template<>
struct Operation<0x7D> : public BaseOperation{
     Operation<0x7D>(){
        traits = OperationTraits(OperationTypes::ADC, AddressModes::ABSX, 0x7D, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x7D>& ins){
        return outs;
    }
};

template<>
struct Operation<0x79> : public BaseOperation{
     Operation<0x79>(){
        traits = OperationTraits(OperationTypes::ADC, AddressModes::ABSY, 0x79, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x79>& ins){
        return outs;
    }
};

template<>
struct Operation<0x61> : public BaseOperation{
     Operation<0x61>(){
        traits = OperationTraits(OperationTypes::ADC, AddressModes::INDIRECT_X, 0x61, 2, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x61>& ins){
        return outs;
    }
};

template<>
struct Operation<0x71> : public BaseOperation{
     Operation<0x71>(){
        traits = OperationTraits(OperationTypes::ADC, AddressModes::INDIRECT_Y, 0x71, 2, 5);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x71>& ins){
        return outs;
    }
};


/**
 * 
 * SBC (Subtract Memory from Accumulator with Borrow)
 * - IMMEDIATE
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * - Absolute Y
 * - Indirect X
 * - Indirect Y
 * 
*/
template<>
struct Operation<0xE9> : public BaseOperation{
     Operation<0xE9>(){
        traits = OperationTraits(OperationTypes::SBC, AddressModes::IMMEDIATE, 0xE9, 2, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xE9>& ins){
        return outs;
    }
};

template<>
struct Operation<0xE5> : public BaseOperation{
     Operation<0xE5>(){
        traits = OperationTraits(OperationTypes::SBC, AddressModes::ZPG, 0xE5, 2, 3);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xE5>& ins){
        return outs;
    }
};

template<>
struct Operation<0xF5> : public BaseOperation{
     Operation<0xF5>(){
        traits = OperationTraits(OperationTypes::SBC, AddressModes::ZPG_X, 0xF5, 2, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xF5>& ins){
        return outs;
    }
};

template<>
struct Operation<0xED> : public BaseOperation{
     Operation<0xED>(){
        traits = OperationTraits(OperationTypes::SBC, AddressModes::ABS, 0xED, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xED>& ins){
        return outs;
    }
};

template<>
struct Operation<0xFD> : public BaseOperation{
     Operation<0xFD>(){
        traits = OperationTraits(OperationTypes::SBC, AddressModes::ABSX, 0xFD, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xFD>& ins){
        return outs;
    }
};

template<>
struct Operation<0xF9> : public BaseOperation{
     Operation<0xF9>(){
        traits = OperationTraits(OperationTypes::SBC, AddressModes::ABSY, 0xF9, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xF9>& ins){
        return outs;
    }
};

template<>
struct Operation<0xE1> : public BaseOperation{
     Operation<0xE1>(){
        traits = OperationTraits(OperationTypes::SBC, AddressModes::INDIRECT_X, 0xE1, 2, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xE1>& ins){
        return outs;
    }
};

template<>
struct Operation<0xF1> : public BaseOperation{
     Operation<0xF1>(){
        traits = OperationTraits(OperationTypes::SBC, AddressModes::INDIRECT_Y, 0xF1, 2, 5);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xF1>& ins){
        return outs;
    }
};


/** Logical Operations **/

/**
 * 
 * AND (AND Memory with Accumulator)
 * - IMMEDIATE
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * - Absolute Y
 * - Indirect X
 * - Indirect Y
 * 
*/

template<>
struct Operation<0x29> : public BaseOperation{
     Operation<0x29>(){
        traits = OperationTraits(OperationTypes::AND, AddressModes::IMMEDIATE, 0x29, 2, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x29>& ins){
        return outs;
    }
};

template<>
struct Operation<0x25> : public BaseOperation{
     Operation<0x25>(){
        traits = OperationTraits(OperationTypes::AND, AddressModes::ZPG, 0x25, 2, 3);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x25>& ins){
        return outs;
    }
};

template<>
struct Operation<0x35> : public BaseOperation{
     Operation<0x35>(){
        traits = OperationTraits(OperationTypes::AND, AddressModes::ZPG_X, 0x35, 2, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x35>& ins){
        return outs;
    }
};

template<>
struct Operation<0x2D> : public BaseOperation{
     Operation<0x2D>(){
        traits = OperationTraits(OperationTypes::AND, AddressModes::ABS, 0x2D, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x2D>& ins){
        return outs;
    }
};

template<>
struct Operation<0x3D> : public BaseOperation{
     Operation<0x3D>(){
        traits = OperationTraits(OperationTypes::AND, AddressModes::ABSX, 0x3D, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x3D>& ins){
        return outs;
    }
};

template<>
struct Operation<0x39> : public BaseOperation{
     Operation<0x39>(){
        traits = OperationTraits(OperationTypes::AND, AddressModes::ABSY, 0x39, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x39>& ins){
        return outs;
    }
};

template<>
struct Operation<0x21> : public BaseOperation{
     Operation<0x21>(){
        traits = OperationTraits(OperationTypes::AND, AddressModes::INDIRECT_X, 0x21, 2, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x21>& ins){
        return outs;
    }
};

template<>
struct Operation<0x31> : public BaseOperation{
     Operation<0x31>(){
        traits = OperationTraits(OperationTypes::AND, AddressModes::INDIRECT_Y, 0x31, 2, 5);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x31>& ins){
        return outs;
    }
};



/**
 * 
 * EOR (Exclusive-OR Memory with Accumulator)
 * - IMMEDIATE
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * - Absolute Y
 * - Indirect X
 * - Indirect Y
 * 
*/

template<>
struct Operation<0x49> : public BaseOperation{
     Operation<0x49>(){
        traits = OperationTraits(OperationTypes::EOR, AddressModes::IMMEDIATE, 0x49, 2, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x49>& ins){
        return outs;
    }
};

template<>
struct Operation<0x45> : public BaseOperation{
     Operation<0x45>(){
        traits = OperationTraits(OperationTypes::EOR, AddressModes::ZPG, 0x45, 2, 3);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x45>& ins){
        return outs;
    }
};

template<>
struct Operation<0x55> : public BaseOperation{
     Operation<0x55>(){
        traits = OperationTraits(OperationTypes::EOR, AddressModes::ZPG_X, 0x55, 2, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x55>& ins){
        return outs;
    }
};

template<>
struct Operation<0x4D> : public BaseOperation{
     Operation<0x4D>(){
        traits = OperationTraits(OperationTypes::EOR, AddressModes::ABS, 0x4D, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x4D>& ins){
        return outs;
    }
};

template<>
struct Operation<0x5D> : public BaseOperation{
     Operation<0x5D>(){
        traits = OperationTraits(OperationTypes::EOR, AddressModes::ABSX, 0x5D, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x5D>& ins){
        return outs;
    }
};

template<>
struct Operation<0x59> : public BaseOperation{
     Operation<0x59>(){
        traits = OperationTraits(OperationTypes::EOR, AddressModes::ABSY, 0x59, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x59>& ins){
        return outs;
    }
};

template<>
struct Operation<0x41> : public BaseOperation{
     Operation<0x41>(){
        traits = OperationTraits(OperationTypes::EOR, AddressModes::INDIRECT_X, 0x41, 2, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x41>& ins){
        return outs;
    }
};

template<>
struct Operation<0x51> : public BaseOperation{
     Operation<0x51>(){
        traits = OperationTraits(OperationTypes::EOR, AddressModes::INDIRECT_Y, 0x51, 2, 5);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x51>& ins){
        return outs;
    }
};



/**
 * 
 * ORA (Or Memory with Accumulator)
 * - IMMEDIATE
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * - Absolute Y
 * - Indirect X
 * - Indirect Y
 * 
*/

template<>
struct Operation<0x09> : public BaseOperation{
     Operation<0x09>(){
        traits = OperationTraits(OperationTypes::ORA, AddressModes::IMMEDIATE, 0x09, 2, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x09>& ins){
        return outs;
    }
};

template<>
struct Operation<0x05> : public BaseOperation{
     Operation<0x05>(){
        traits = OperationTraits(OperationTypes::ORA, AddressModes::ZPG, 0x05, 2, 3);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x05>& ins){
        return outs;
    }
};

template<>
struct Operation<0x15> : public BaseOperation{
     Operation<0x15>(){
        traits = OperationTraits(OperationTypes::ORA, AddressModes::ZPG_X, 0x15, 2, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x15>& ins){
        return outs;
    }
};

template<>
struct Operation<0x0D> : public BaseOperation{
     Operation<0x0D>(){
        traits = OperationTraits(OperationTypes::ORA, AddressModes::ABS, 0x0D, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x0D>& ins){
        return outs;
    }
};

template<>
struct Operation<0x1D> : public BaseOperation{
     Operation<0x1D>(){
        traits = OperationTraits(OperationTypes::ORA, AddressModes::ABSX, 0x1D, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x1D>& ins){
        return outs;
    }
};

template<>
struct Operation<0x19> : public BaseOperation{
     Operation<0x19>(){
        traits = OperationTraits(OperationTypes::ORA, AddressModes::ABSY, 0x19, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x19>& ins){
        return outs;
    }
};

template<>
struct Operation<0x01> : public BaseOperation{
     Operation<0x01>(){
        traits = OperationTraits(OperationTypes::ORA, AddressModes::INDIRECT_X, 0x01, 2, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x01>& ins){
        return outs;
    }
};

template<>
struct Operation<0x11> : public BaseOperation{
     Operation<0x11>(){
        traits = OperationTraits(OperationTypes::ORA, AddressModes::INDIRECT_Y, 0x11, 2, 5);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x11>& ins){
        return outs;
    }
};




/** Shihft & Rotate Instructions **/

/**
 * 
 * ASL (Shift Left One Bit(Memory or Accumulator) )
 * - Accumulator (A)
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * 
*/


template<>
struct Operation<0x0A> : public BaseOperation{
     Operation<0x0A>(){
        traits = OperationTraits(OperationTypes::ASL, AddressModes::A, 0x0A, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x0A>& ins){
        return outs;
    }
};


template<>
struct Operation<0x06> : public BaseOperation{
     Operation<0x06>(){
        traits = OperationTraits(OperationTypes::ASL, AddressModes::ZPG, 0x06, 2, 5);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x06>& ins){
        return outs;
    }
};

template<>
struct Operation<0x16> : public BaseOperation{
     Operation<0x16>(){
        traits = OperationTraits(OperationTypes::ASL, AddressModes::ZPG_X, 0x16, 2, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x16>& ins){
        return outs;
    }
};

template<>
struct Operation<0x0E> : public BaseOperation{
     Operation<0x0E>(){
        traits = OperationTraits(OperationTypes::ASL, AddressModes::ABS, 0x0E, 3, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x0E>& ins){
        return outs;
    }
};

template<>
struct Operation<0x1E> : public BaseOperation{
     Operation<0x1E>(){
        traits = OperationTraits(OperationTypes::ASL, AddressModes::ABSX, 0x1E, 3, 7);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x1E>& ins){
        return outs;
    }
};

/**
 * 
 * 
 * LSR (Shift One Bit Right ** Memory or Accumulator **)
 * - Immediate
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * 
*/

template<>
struct Operation<0x4A> : public BaseOperation{
     Operation<0x4A>(){
        traits = OperationTraits(OperationTypes::LSR, AddressModes::A, 0x4A, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x4A>& ins){
        return outs;
    }
};

template<>
struct Operation<0x46> : public BaseOperation{
     Operation<0x46>(){
        traits = OperationTraits(OperationTypes::LSR, AddressModes::ZPG, 0x46, 2, 5);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x46>& ins){
        return outs;
    }
};

template<>
struct Operation<0x56> : public BaseOperation{
     Operation<0x56>(){
        traits = OperationTraits(OperationTypes::LSR, AddressModes::ZPG_X, 0x56, 2, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x56>& ins){
        return outs;
    }
};

template<>
struct Operation<0x4E> : public BaseOperation{
     Operation<0x4E>(){
        traits = OperationTraits(OperationTypes::LSR, AddressModes::ABS, 0x4E, 3, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x4E>& ins){
        return outs;
    }
};

template<>
struct Operation<0x5E> : public BaseOperation{
     Operation<0x5E>(){
        traits = OperationTraits(OperationTypes::LSR, AddressModes::ABSX, 0x5E, 3, 7);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x5E>& ins){
        return outs;
    }
};


/**
 * 
 * ROL (Rotate One Bit Left (Memory or Accumulator) )
 * - Accumulator (A)
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * 
*/

template<>
struct Operation<0x2A> : public BaseOperation{
     Operation<0x2A>(){
        traits = OperationTraits(OperationTypes::ROL, AddressModes::A, 0x2A, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x2A>& ins){
        return outs;
    }
};

template<>
struct Operation<0x26> : public BaseOperation{
     Operation<0x26>(){
        traits = OperationTraits(OperationTypes::ROL, AddressModes::ZPG, 0x26, 2, 5);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x26>& ins){
        return outs;
    }
};

template<>
struct Operation<0x36> : public BaseOperation{
     Operation<0x36>(){
        traits = OperationTraits(OperationTypes::ROL, AddressModes::ZPG_X, 0x36, 2, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x36>& ins){
        return outs;
    }
};

template<>
struct Operation<0x2E> : public BaseOperation{
     Operation<0x2E>(){
        traits = OperationTraits(OperationTypes::ROL, AddressModes::ABS, 0x2E, 3, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x2E>& ins){
        return outs;
    }
};

template<>
struct Operation<0x3E> : public BaseOperation{
     Operation<0x3E>(){
        traits = OperationTraits(OperationTypes::ROL, AddressModes::ABSX, 0x3E, 3, 7);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x3E>& ins){
        return outs;
    }
};


/**
 * 
 * ROR (Rotate One Bit Right (Memory or Accumulator) )
 * - Accumulator (A)
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * 
*/

template<>
struct Operation<0x6A> : public BaseOperation{
     Operation<0x6A>(){
        traits = OperationTraits(OperationTypes::ROR, AddressModes::A, 0x6A, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x6A>& ins){
        return outs;
    }
};

template<>
struct Operation<0x66> : public BaseOperation{
     Operation<0x66>(){
        traits = OperationTraits(OperationTypes::ROR, AddressModes::ZPG, 0x66, 2, 5);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x66>& ins){
        return outs;
    }
};

template<>
struct Operation<0x76> : public BaseOperation{
     Operation<0x76>(){
        traits = OperationTraits(OperationTypes::ROR, AddressModes::ZPG_X, 0x76, 2, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x76>& ins){
        return outs;
    }
};

template<>
struct Operation<0x6E> : public BaseOperation{
     Operation<0x6E>(){
        traits = OperationTraits(OperationTypes::ROR, AddressModes::ABS, 0x6E, 3, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x6E>& ins){
        return outs;
    }
};

template<>
struct Operation<0x7E> : public BaseOperation{
     Operation<0x7E>(){
        traits = OperationTraits(OperationTypes::ROR, AddressModes::ABSX, 0x7E, 3, 7);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x7E>& ins){
        return outs;
    }
};


/** Flag Instructions **/

/*
    CLC (Clear Carry Flag)
    - IMPLIED
*/

template<>
struct Operation<0x18> : public BaseOperation{
     Operation<0x18>(){
        traits = OperationTraits(OperationTypes::CLC, AddressModes::IMPLIED, 0x18, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x18>& ins){
        return outs;
    }
};


/**
 * 
 * CLD (Clear Decimal Mode)
 * - IMPLIED
*/

template<>
struct Operation<0xD8> : public BaseOperation{
     Operation<0xD8>(){
        traits = OperationTraits(OperationTypes::CLD, AddressModes::IMPLIED, 0xD8, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xD8>& ins){
        return outs;
    }
};

/**
 * 
 * CLI (Clear Interrupt Disable Bit)
 * - IMPLIED
*/

template<>
struct Operation<0x58> : public BaseOperation{
     Operation<0x58>(){
        traits = OperationTraits(OperationTypes::CLI, AddressModes::IMPLIED, 0x58, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x58>& ins){
        return outs;
    }
};

/**
 * 
 * CLV (Clear Overflow Flag)
 * - IMPLIED
*/

template<>
struct Operation<0xB8> : public BaseOperation{
     Operation<0xB8>(){
        traits = OperationTraits(OperationTypes::CLV, AddressModes::IMPLIED, 0xB8, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xB8>& ins){
        return outs;
    }
};

/**
 * 
 * SEC (Set Carry Flag)
 * - IMPLIED
*/

template<>
struct Operation<0x38> : public BaseOperation{
     Operation<0x38>(){
        traits = OperationTraits(OperationTypes::SEC, AddressModes::IMPLIED, 0x38, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x38>& ins){
        return outs;
    }
};

/**
 * 
 * SED (Set Decimal Flag)
 * - IMPLIED
*/

template<>
struct Operation<0xF8> : public BaseOperation{
     Operation<0xF8>(){
        traits = OperationTraits(OperationTypes::SED, AddressModes::IMPLIED, 0xF8, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xF8>& ins){
        return outs;
    }
};

/**
 * 
 * SEI (Set Interrupt Disable Status)
 * - IMPLIED
*/

template<>
struct Operation<0x78> : public BaseOperation{
     Operation<0x78>(){
        traits = OperationTraits(OperationTypes::SEI, AddressModes::IMPLIED, 0x78, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x78>& ins){
        return outs;
    }
};



/** Comparisons Instructions **/

/**
 * 
 * CMP (Compare Memory with Accumulator)
 * 
 * - IMMEDIATE
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * - Absolute Y
 * - Indirect X
 * - Indirect Y
 * 
*/

template<>
struct Operation<0xC9> : public BaseOperation{
     Operation<0xC9>(){
        traits = OperationTraits(OperationTypes::CMP, AddressModes::IMMEDIATE, 0xC9, 2, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xC9>& ins){
        return outs;
    }
};

template<>
struct Operation<0xC5> : public BaseOperation{
     Operation<0xC5>(){
        traits = OperationTraits(OperationTypes::CMP, AddressModes::ZPG, 0xC5, 2, 3);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xC5>& ins){
        return outs;
    }
};

template<>
struct Operation<0xD5> : public BaseOperation{
     Operation<0xD5>(){
        traits = OperationTraits(OperationTypes::CMP, AddressModes::ZPG_X, 0xD5, 2, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xD5>& ins){
        return outs;
    }
};

template<>
struct Operation<0xCD> : public BaseOperation{
     Operation<0xCD>(){
        traits = OperationTraits(OperationTypes::CMP, AddressModes::ABS, 0xCD, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xCD>& ins){
        return outs;
    }
};

template<>
struct Operation<0xDD> : public BaseOperation{
     Operation<0xDD>(){
        traits = OperationTraits(OperationTypes::CMP, AddressModes::ABSX, 0xDD, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xDD>& ins){
        return outs;
    }
};

template<>
struct Operation<0xD9> : public BaseOperation{
     Operation<0xD9>(){
        traits = OperationTraits(OperationTypes::CMP, AddressModes::ABSY, 0xD9, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xD9>& ins){
        return outs;
    }
};

template<>
struct Operation<0xC1> : public BaseOperation{
     Operation<0xC1>(){
        traits = OperationTraits(OperationTypes::CMP, AddressModes::INDIRECT_X, 0xC1, 2, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xC1>& ins){
        return outs;
    }
};

template<>
struct Operation<0xD1> : public BaseOperation{
     Operation<0xD1>(){
        traits = OperationTraits(OperationTypes::CMP, AddressModes::INDIRECT_Y, 0xD1, 2, 5);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xD1>& ins){
        return outs;
    }
};

/**
 * 
 * CPX (Compare Memory and Index X)
 * 
 * - IMMEDIATE
 * - ZeroPage
 * - Absolute
 * 
*/

template<>
struct Operation<0xE0> : public BaseOperation{
     Operation<0xE0>(){
        traits = OperationTraits(OperationTypes::CPX, AddressModes::IMMEDIATE, 0xE0, 2, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xE0>& ins){
        return outs;
    }
};


template<>
struct Operation<0xE4> : public BaseOperation{
     Operation<0xE4>(){
        traits = OperationTraits(OperationTypes::CPX, AddressModes::ZPG, 0xE4, 2, 3);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xE4>& ins){
        return outs;
    }
};

template<>
struct Operation<0xEC> : public BaseOperation{
     Operation<0xEC>(){
        traits = OperationTraits(OperationTypes::CPX, AddressModes::ABS, 0xEC, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xEC>& ins){
        return outs;
    }
};

/**
 * 
 * CPY (Compare Memory and Index Y)
 * 
 * - IMMEDIATE
 * - ZeroPage
 * - Absolute
 * 
*/

template<>
struct Operation<0xC0> : public BaseOperation{
    Operation<0xC0>(){
        traits = OperationTraits(OperationTypes::CPY, AddressModes::IMMEDIATE, 0xC0, 2, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xC0>& ins){
        return outs;
    }
};


template<>
struct Operation<0xC4> : public BaseOperation{
     Operation<0xC4>(){
        traits = OperationTraits(OperationTypes::CPY, AddressModes::ZPG, 0xC4, 2, 3);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xC4>& ins){
        return outs;
    }
};

template<>
struct Operation<0xCC> : public BaseOperation{
     Operation<0xCC>(){
        traits = OperationTraits(OperationTypes::CPY, AddressModes::ABS, 0xCC, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xCC>& ins){
        return outs;
    }
};


/** Conditional Branchh Instructions **/

/**
 * 
 * BCC (Branch on Carry Clear)
 * - RELATIVE
 * 
*/

template<>
struct Operation<0x90> : public BaseOperation{
    Operation<0x90>(){
        traits = OperationTraits(OperationTypes::BCC, AddressModes::RELATIVE, 0x90, 2, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x90>& ins){
        return outs;
    }
};

/**
 * 
 * BCS (Branch on Carry Set)
 * - RELATIVE
 * 
*/

template<>
struct Operation<0xB0> : public BaseOperation{
    Operation<0xB0>(){
        traits = OperationTraits(OperationTypes::BCS, AddressModes::RELATIVE, 0xB0, 2, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xB0>& ins){
        return outs;
    }
};

/**
 * 
 * BEQ (Branch on Result Zero)
 * - RELATIVE
 * 
*/

template<>
struct Operation<0xF0> : public BaseOperation{
    Operation<0xF0>(){
        traits = OperationTraits(OperationTypes::BEQ, AddressModes::RELATIVE, 0xF0, 2, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xF0>& ins){
        return outs;
    }
};

/**
 * 
 * BMI (Branch on Result Minus)
 * - RELATIVE
 * 
*/

template<>
struct Operation<0x30> : public BaseOperation{
    Operation<0x30>(){
        traits = OperationTraits(OperationTypes::BMI, AddressModes::RELATIVE, 0x30, 2, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x30>& ins){
        return outs;
    }
};

/**
 * 
 * BNE (Branch on Result not Zero)
 * - RELATIVE
 * 
*/

template<>
struct Operation<0xD0> : public BaseOperation{
    Operation<0xD0>(){
        traits = OperationTraits(OperationTypes::BNE, AddressModes::RELATIVE, 0xD0, 2, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xD0>& ins){
        return outs;
    }
};

/**
 * 
 * BPL (Branch on Result Plus)
 * - RELATIVE
 * 
*/

template<>
struct Operation<0x10> : public BaseOperation{
    Operation<0x10>(){
        traits = OperationTraits(OperationTypes::BPL, AddressModes::RELATIVE, 0x10, 2, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x10>& ins){
        return outs;
    }
};

/**
 * 
 * BVC (Branch on Overflow Clear)
 * - RELATIVE
 * 
*/

template<>
struct Operation<0x50> : public BaseOperation{
    Operation<0x50>(){
        traits = OperationTraits(OperationTypes::BVC, AddressModes::RELATIVE, 0x50, 2, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x50>& ins){
        return outs;
    }
};

/**
 * 
 * BVS (Branch on Overflow Set)
 * - RELATIVE
 * 
*/

template<>
struct Operation<0x70> : public BaseOperation{
    Operation<0x70>(){
        traits = OperationTraits(OperationTypes::BVS, AddressModes::RELATIVE, 0x70, 2, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x70>& ins){
        return outs;
    }
};


/** Jump and Subroutines **/

/**
 * 
 * JMP (Jump to New Location)
 * - Absolute
 * - Indirect
 * 
*/

template<>
struct Operation<0x4C> : public BaseOperation{
    Operation<0x4C>(){
        traits = OperationTraits(OperationTypes::JMP, AddressModes::ABS, 0x4C, 3, 3);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x4C>& ins){
        return outs;
    }
};

template<>
struct Operation<0x6C> : public BaseOperation{
    Operation<0x6C>(){
        traits = OperationTraits(OperationTypes::JMP, AddressModes::INDIRECT, 0x6C, 3, 5);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x6C>& ins){
        return outs;
    }
};



/**
 * 
 * JSR (Jump to New Location Saving Return Address)
 * - Absolute
 * 
*/

template<>
struct Operation<0x20> : public BaseOperation{
    Operation<0x20>(){
        traits = OperationTraits(OperationTypes::JSR, AddressModes::ABS, 0x20, 3, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x20>& ins){
        return outs;
    }
};



/**
 * 
 * RTS (Return from Subroutine)
 * - IMPLIED
 * 
*/

template<>
struct Operation<0x60> : public BaseOperation{
    Operation<0x60>(){
        traits = OperationTraits(OperationTypes::RTS, AddressModes::IMPLIED, 0x60, 1, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x60>& ins){
        return outs;
    }
};


/** Interrupts **/

/**
 * 
 * BRK (Force Break)
 * - IMPLIED
 * 
*/
template<>
struct Operation<0x00> : public BaseOperation{
    Operation<0x00>(){
        traits = OperationTraits(OperationTypes::BRK, AddressModes::IMPLIED, 0x00, 1, 7);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x00>& ins){
        return outs;
    }
};

/**
 * 
 * RTI (Return from Interrupt)
 * - IMPLIED
 * 
*/
template<>
struct Operation<0x40> : public BaseOperation{
    Operation<0x40>(){
        traits = OperationTraits(OperationTypes::RTI, AddressModes::IMPLIED, 0x40, 1, 6);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x40>& ins){
        return outs;
    }
};


/** Other Instruction Options **/

/**
 * 
 * BIT (Test Bits in Memory with Accumulator)
 * - ZeroPage
 * - Absolute
 * 
*/

template<>
struct Operation<0x24> : public BaseOperation{
    Operation<0x24>(){
        traits = OperationTraits(OperationTypes::BIT, AddressModes::ZPG, 0x24, 2, 3);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x24>& ins){
        return outs;
    }
};

template<>
struct Operation<0x2C> : public BaseOperation{
    Operation<0x2C>(){
        traits = OperationTraits(OperationTypes::BIT, AddressModes::ABS, 0x2C, 3, 4);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0x2C>& ins){
        return outs;
    }
};

/**
 * 
 * NOP (No Operation)
 * - ZeroPage
 * - Absolute
 * 
*/
template<>
struct Operation<0xEA> : public BaseOperation{
    Operation<0xEA>(){
        traits = OperationTraits(OperationTypes::NOP, AddressModes::IMPLIED, 0xEA, 1, 2);
    }

    void execute(){
    }

    OperationTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Operation<0xEA>& ins){
        return outs;
    }
};
