echo "creating full size bin..."
dd if=/dev/zero of=floppy_boot.img bs=1024 count=1440
dd if=bin/os.bin of=floppy_boot.img conv=notrunc
mv floppy_boot.img ./iso

echo "creating iso..."
genisoimage -o oscd.iso -b ./iso/floppy_boot.img ./iso

echo "blanking disk..."
wodim dev=/dev/sg1 blank=fast

echo "writing to disk..."
wodim -v -eject speed=4 dev=/dev/sg1 ./iso/oscd.iso
