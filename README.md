# MongoPact

MongoPact is an open-source application written in C that provides backup functionality for MongoDB databases. It supports full and incremental backups, compression and encryption of backup files, remote backup storage, scheduling of regular backups, and the ability to backup multiple databases.

## Installation

To install MongoPact, follow these steps:

1. Clone the repository: `git clone https://github.com/pakabah/mongopact.git`
2. Navigate to the cloned directory: `cd mongopact`
3. Compile the application: `make`
4. Install the application: `make install`

## Usage

To use MongoPact, follow these steps:

1. Open a terminal window and navigate to the directory where you want to store the backup file.
2. Enter the following command: `mongopact backup -d database_name -o backup_file_name`
   - Replace `database_name` with the name of the database you want to backup.
   - Replace `backup_file_name` with the name you want to give the backup file.
3. If you want to schedule regular backups, use the following command: `mongopact schedule -d database_name -o backup_file_name -s "cron_syntax"`
   - Replace `cron_syntax` with the cron syntax for the backup schedule you want to set.

For more detailed usage instructions, see the [Usage Guide](./docs/usage.md).

## Features

- Full and incremental backup options
- Compression and encryption of backup files
- Support for remote backup storage
- Command-line interface for easy use
- Scheduling of regular backups using cron syntax
- Ability to backup multiple databases

## Contributing

If you want to contribute to MongoPact, follow the guidelines in [CONTRIBUTING.md](./CONTRIBUTING.md).

## License

MongoPact is released under the [MIT License](./LICENSE).

