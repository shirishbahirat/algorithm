#include <iostream>

using namespace std;

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
  int (*seek)(struct file *, char *, int, int *);
  int (*read)(struct file *, char *, int, int *);
  int (*write)(struct file *, char *, int, int *);
  int (*release)(struct file *, struct dir_context *);
};

int dev_open(struct inode *nnode, struct file *fl)
{
  cout << "dev open" << endl;
  return 0;
}
int dev_seek(struct file *fl, char *name, int id, int *ptr)
{
  cout << "dev seek" << endl;
  return 0;
}
int dev_read(struct file *fl, char *name, int id, int *ptr)
{
  cout << "dev read" << endl;
  return 0;
}
int dev_write(struct file *fl, char *name, int id, int *ptr)
{
  cout << "dev write" << endl;
  return 0;
}
int dev_release(struct file *fl, struct dir_context *cntx)
{
  cout << "dev release" << endl;
  return 0;
}

#define LOAD_DRIVER(open, read, seek, write, release)                          \
  {.open = open, .read = read, .write = write, .release = release};

typedef struct DEFAULT_XXX_STRUCT
{
  int data_time;
  int data;
} SomeSetting;

int main(int argc, char const *argv[])
{

  static struct file_operations fops = {
      .open = dev_open,
      .read = dev_read,
      .seek = dev_seek,
      .write = dev_write,
      .release = dev_release,
  };

  inode nd;
  file fl;
  fops.open(&nd, &fl);

  return 0;
}
