#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mongoc/mongoc.h>
#include <getopt.h>

static const char *uri_string = "mongodb://localhost:27017";
static const char *schedule_string = NULL;
static const char *db_name = NULL;
static int is_full = 0;
static int is_incremental = 0;
static int is_compress = 0;
static int is_encrypt = 0;

static void usage() {
  printf("Usage: mongopact [OPTIONS]\n");
  printf("Options:\n");
  printf("  --full             Perform a full backup\n");
  printf("  --incremental      Perform an incremental backup\n");
  printf("  --compress         Compress the backup data\n");
  printf("  --encrypt          Encrypt the backup data\n");
  printf("  --schedule STRING  Schedule the backup using a cron-like STRING\n");
  printf("  --uri STRING       MongoDB connection string (default: %s)\n", uri_string);
  printf("  --db NAME          MongoDB database name (required)\n");
  printf("  -h, --help         Show this help message and exit\n");
}

static void parse_args(int argc, char *argv[]) {
  int opt;
  static struct option long_options[] = {
    {"full", no_argument, &is_full, 1},
    {"incremental", no_argument, &is_incremental, 1},
    {"compress", no_argument, &is_compress, 1},
    {"encrypt", no_argument, &is_encrypt, 1},
    {"schedule", required_argument, NULL, 's'},
    {"uri", required_argument, NULL, 'u'},
    {"db", required_argument, NULL, 'd'},
    {"help", no_argument, NULL, 'h'},
    {NULL, 0, NULL, 0}
  };

  while ((opt = getopt_long(argc, argv, "hs:u:d:", long_options, NULL)) != -1) {
    switch (opt) {
      case 0:
        break;
      case 's':
        schedule_string = optarg;
        break;
      case 'u':
        uri_string = optarg;
        break;
      case 'd':
        db_name = optarg;
        break;
      case 'h':
      default:
        usage();
        exit(EXIT_FAILURE);
    }
  }

  if (!is_full && !is_incremental) {
    fprintf(stderr, "Error: either --full or --incremental must be specified\n");
    usage();
    exit(EXIT_FAILURE);
  }

  if (db_name == NULL) {
    fprintf(stderr, "Error: --db is a required argument\n");
    usage();
    exit(EXIT_FAILURE);
  }
}


int main(int argc, char *argv[]) {

  // Parse command-line arguments
  parse_args(argc, argv);

  return 0;
}

