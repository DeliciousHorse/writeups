import idaapi
import idc
import ida_dbg
import string
import time

def add_bp(addr, fun):
	add_bpt(addr, 0, BPT_SOFT)
	enable_bpt(addr, True)
	SetBptCnd(addr, fun)

def dump_stack():
	rsp = GetRegValue("RSP")
	stack_addr = Qword(rsp + 0x1398)
	stack_top = Qword(rsp + 0x13b0)
	if stack_top == 0:
		return ''
	result = '('
	for i in range(stack_top):
		result += hex(Qword(stack_addr + (i+1)*8))[:-1] + '|'
	result = result[:-1] + ')'
	return result

def get_imm(start, stop):
	ip = GetRegValue("RAX")
	bytecode = GetRegValue("RBX")
	val = get_bytes(bytecode+ip+start, stop-start)
	return hex(int(val))

log_file = open('log_file', 'w')
def dump_instr():
	global shuff
	instr = chr(GetRegValue("ESI") & 0xFF)
	rsp = GetRegValue("RSP")
	handler_str = GetString(rsp + 0x48)
	index = handler_str.index(instr)
	
	stck_dmp = dump_stack()
	decoded = ''
	if index == 0:
		decoded += 'sub\t'
	elif index == 1:
		decoded += 'add\t'
	elif index == 2:
		decoded += 'neg\t'
	elif index == 3:
		decoded += 'mul\t'
	elif index == 4:
		decoded += 'mod\t'
	elif index == 5:
		decoded += 'push '
		num = get_imm(1, 0x15)
		decoded += '(' + num + ')\t'
	elif index == 6:
		decoded += 'pop(ignore)\t'
	elif index == 7:
		decoded += 'read_input\t'
	elif index == 8:
		decoded += 'print_output\t'
	elif index == 9:
		decoded = 'dup\t'
	elif index == 0xA:
		decoded += 'save at '
		num = get_imm(1, 3)
		decoded += '(' + num + ')\t'
	elif index == 0xB:
		decoded += 'load at '
		num = get_imm(1, 3)
		decoded += '(' + num + ')\t'
	elif index == 0xC:
		decoded += 'pop to lower\t'
	elif index == 0xD:
		decoded += 'shl\t'
	elif index == 0xE:
		decoded += 'cmp\t'
	elif index == 0xF:
		decoded += 'shuffle\t'

	decoded += stck_dmp 
	log_file.write(decoded+'\n')
	log_file.flush()
	

RunPlugin("python", 3)
vm_loop = 0x0487707
add_bp(vm_loop, "dump_instr()")
start_process(None, None, None)