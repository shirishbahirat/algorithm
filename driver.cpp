#include <iostream>

struct inode
{
  char *name;
  int fid;
};

struct file
{
  char *name;
  int fid;
  int ptr;
};

struct dir_context
{
  char *dir;
};

struct file_operations
{
  struct module *owner;
  int (*open)(struct inode *, struct file *);
  int (*seek)(struct file *, int, int);
  int (*read)(struct file *, char *, int, int *);
  int (*write)(struct file *, const char *, int, int *);
  int (*release)(struct file *, struct dir_context *);
};

int dev_open(struct inode *nnode, struct file *fl) { return 0; }
int dev_seek(struct file *fl, char *name, int id, int *ptr) { return 0; }
int dev_read(struct file *fl, char *name, int id, int *ptr) { return 0; }
int dev_write(struct file *fl, char *name, int id, int *ptr) { return 0; }
int dev_release(struct file *fl, struct dir_context *cntx) { return 0; }

int main(int argc, char const *argv[])
{

  static struct file_operations fops = {
      .open = dev_open,
      .read = dev_read,
      .seek = dev_seek,
      .write = dev_write,
      .release = dev_release,
  };

  return 0;
}
