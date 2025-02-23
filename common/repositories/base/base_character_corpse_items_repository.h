/**
 * DO NOT MODIFY THIS FILE
 *
 * This repository was automatically generated and is NOT to be modified directly.
 * Any repository modifications are meant to be made to the repository extending the base.
 * Any modifications to base repositories are to be made by the generator only
 *
 * @generator ./utils/scripts/generators/repository-generator.pl
 * @docs https://eqemu.gitbook.io/server/in-development/developer-area/repositories
 */

#ifndef EQEMU_BASE_CHARACTER_CORPSE_ITEMS_REPOSITORY_H
#define EQEMU_BASE_CHARACTER_CORPSE_ITEMS_REPOSITORY_H

#include "../../database.h"
#include "../../string_util.h"

class BaseCharacterCorpseItemsRepository {
public:
	struct CharacterCorpseItems {
		int corpse_id;
		int charid;
		int equip_slot;
		int item_id;
		int charges;
		int aug_1;
		int aug_2;
		int aug_3;
		int aug_4;
		int aug_5;
		int aug_6;
		int attuned;
	};

	static std::string PrimaryKey()
	{
		return std::string("corpse_id");
	}

	static std::vector<std::string> Columns()
	{
		return {
			"corpse_id",
			"charid",
			"equip_slot",
			"item_id",
			"charges",
			"aug_1",
			"aug_2",
			"aug_3",
			"aug_4",
			"aug_5",
			"aug_6",
			"attuned",
		};
	}

	static std::string ColumnsRaw()
	{
		return std::string(implode(", ", Columns()));
	}

	static std::string TableName()
	{
		return std::string("character_corpse_items");
	}

	static std::string BaseSelect()
	{
		return fmt::format(
			"SELECT {} FROM {}",
			ColumnsRaw(),
			TableName()
		);
	}

	static std::string BaseInsert()
	{
		return fmt::format(
			"INSERT INTO {} ({}) ",
			TableName(),
			ColumnsRaw()
		);
	}

	static CharacterCorpseItems NewEntity()
	{
		CharacterCorpseItems entry{};

		entry.corpse_id  = 0;
		entry.charid = 0;
		entry.equip_slot = 0;
		entry.item_id    = 0;
		entry.charges    = 0;
		entry.aug_1      = 0;
		entry.aug_2      = 0;
		entry.aug_3      = 0;
		entry.aug_4      = 0;
		entry.aug_5      = 0;
		entry.aug_6      = 0;
		entry.attuned    = 0;

		return entry;
	}

	static CharacterCorpseItems GetCharacterCorpseItemsEntry(
		const std::vector<CharacterCorpseItems> &character_corpse_itemss,
		int character_corpse_items_id
	)
	{
		for (auto &character_corpse_items : character_corpse_itemss) {
			if (character_corpse_items.corpse_id == character_corpse_items_id) {
				return character_corpse_items;
			}
		}

		return NewEntity();
	}

	static CharacterCorpseItems FindOne(
		Database& db,
		int character_corpse_items_id
	)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"{} WHERE id = {} LIMIT 1",
				BaseSelect(),
				character_corpse_items_id
			)
		);

		auto row = results.begin();
		if (results.RowCount() == 1) {
			CharacterCorpseItems entry{};

			entry.corpse_id  = atoi(row[0]);
			entry.charid     = atoi(row[1]);
			entry.equip_slot = atoi(row[2]);
			entry.item_id    = atoi(row[3]);
			entry.charges    = atoi(row[4]);
			entry.aug_1      = atoi(row[5]);
			entry.aug_2      = atoi(row[6]);
			entry.aug_3      = atoi(row[7]);
			entry.aug_4      = atoi(row[8]);
			entry.aug_5      = atoi(row[9]);
			entry.aug_6      = atoi(row[10]);
			entry.attuned    = atoi(row[11]);

			return entry;
		}

		return NewEntity();
	}

	static int DeleteOne(
		Database& db,
		int character_corpse_items_id
	)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {} = {}",
				TableName(),
				PrimaryKey(),
				character_corpse_items_id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int UpdateOne(
		Database& db,
		CharacterCorpseItems character_corpse_items_entry
	)
	{
		std::vector<std::string> update_values;

		auto columns = Columns();

		update_values.push_back(columns[0] + " = " + std::to_string(character_corpse_items_entry.corpse_id));
		update_values.push_back(columns[1] + " = " + std::to_string(character_corpse_items_entry.charid));
		update_values.push_back(columns[2] + " = " + std::to_string(character_corpse_items_entry.equip_slot));
		update_values.push_back(columns[3] + " = " + std::to_string(character_corpse_items_entry.item_id));
		update_values.push_back(columns[4] + " = " + std::to_string(character_corpse_items_entry.charges));
		update_values.push_back(columns[5] + " = " + std::to_string(character_corpse_items_entry.aug_1));
		update_values.push_back(columns[6] + " = " + std::to_string(character_corpse_items_entry.aug_2));
		update_values.push_back(columns[7] + " = " + std::to_string(character_corpse_items_entry.aug_3));
		update_values.push_back(columns[8] + " = " + std::to_string(character_corpse_items_entry.aug_4));
		update_values.push_back(columns[9] + " = " + std::to_string(character_corpse_items_entry.aug_5));
		update_values.push_back(columns[10] + " = " + std::to_string(character_corpse_items_entry.aug_6));
		update_values.push_back(columns[11] + " = " + std::to_string(character_corpse_items_entry.attuned));

		auto results = db.QueryDatabase(
			fmt::format(
				"UPDATE {} SET {} WHERE {} = {}",
				TableName(),
				implode(", ", update_values),
				PrimaryKey(),
				character_corpse_items_entry.corpse_id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static CharacterCorpseItems InsertOne(
		Database& db,
		CharacterCorpseItems character_corpse_items_entry
	)
	{
		std::vector<std::string> insert_values;

		insert_values.push_back(std::to_string(character_corpse_items_entry.corpse_id));
		insert_values.push_back(std::to_string(character_corpse_items_entry.charid));
		insert_values.push_back(std::to_string(character_corpse_items_entry.equip_slot));
		insert_values.push_back(std::to_string(character_corpse_items_entry.item_id));
		insert_values.push_back(std::to_string(character_corpse_items_entry.charges));
		insert_values.push_back(std::to_string(character_corpse_items_entry.aug_1));
		insert_values.push_back(std::to_string(character_corpse_items_entry.aug_2));
		insert_values.push_back(std::to_string(character_corpse_items_entry.aug_3));
		insert_values.push_back(std::to_string(character_corpse_items_entry.aug_4));
		insert_values.push_back(std::to_string(character_corpse_items_entry.aug_5));
		insert_values.push_back(std::to_string(character_corpse_items_entry.aug_6));
		insert_values.push_back(std::to_string(character_corpse_items_entry.attuned));

		auto results = db.QueryDatabase(
			fmt::format(
				"{} VALUES ({})",
				BaseInsert(),
				implode(",", insert_values)
			)
		);

		if (results.Success()) {
			character_corpse_items_entry.corpse_id = results.LastInsertedID();
			return character_corpse_items_entry;
		}

		character_corpse_items_entry = NewEntity();

		return character_corpse_items_entry;
	}

	static int InsertMany(
		Database& db,
		std::vector<CharacterCorpseItems> character_corpse_items_entries
	)
	{
		std::vector<std::string> insert_chunks;

		for (auto &character_corpse_items_entry: character_corpse_items_entries) {
			std::vector<std::string> insert_values;

			insert_values.push_back(std::to_string(character_corpse_items_entry.corpse_id));
			insert_values.push_back(std::to_string(character_corpse_items_entry.charid));
			insert_values.push_back(std::to_string(character_corpse_items_entry.equip_slot));
			insert_values.push_back(std::to_string(character_corpse_items_entry.item_id));
			insert_values.push_back(std::to_string(character_corpse_items_entry.charges));
			insert_values.push_back(std::to_string(character_corpse_items_entry.aug_1));
			insert_values.push_back(std::to_string(character_corpse_items_entry.aug_2));
			insert_values.push_back(std::to_string(character_corpse_items_entry.aug_3));
			insert_values.push_back(std::to_string(character_corpse_items_entry.aug_4));
			insert_values.push_back(std::to_string(character_corpse_items_entry.aug_5));
			insert_values.push_back(std::to_string(character_corpse_items_entry.aug_6));
			insert_values.push_back(std::to_string(character_corpse_items_entry.attuned));

			insert_chunks.push_back("(" + implode(",", insert_values) + ")");
		}

		std::vector<std::string> insert_values;

		auto results = db.QueryDatabase(
			fmt::format(
				"{} VALUES {}",
				BaseInsert(),
				implode(",", insert_chunks)
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static std::vector<CharacterCorpseItems> All(Database& db)
	{
		std::vector<CharacterCorpseItems> all_entries;

		auto results = db.QueryDatabase(
			fmt::format(
				"{}",
				BaseSelect()
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			CharacterCorpseItems entry{};

			entry.corpse_id  = atoi(row[0]);
			entry.charid     = atoi(row[1]);
			entry.equip_slot = atoi(row[2]);
			entry.item_id    = atoi(row[3]);
			entry.charges    = atoi(row[4]);
			entry.aug_1      = atoi(row[5]);
			entry.aug_2      = atoi(row[6]);
			entry.aug_3      = atoi(row[7]);
			entry.aug_4      = atoi(row[8]);
			entry.aug_5      = atoi(row[9]);
			entry.aug_6      = atoi(row[10]);
			entry.attuned    = atoi(row[11]);

			all_entries.push_back(entry);
		}

		return all_entries;
	}

	static std::vector<CharacterCorpseItems> GetWhere(Database& db, std::string where_filter)
	{
		std::vector<CharacterCorpseItems> all_entries;

		auto results = db.QueryDatabase(
			fmt::format(
				"{} WHERE {}",
				BaseSelect(),
				where_filter
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			CharacterCorpseItems entry{};

			entry.corpse_id  = atoi(row[0]);
			entry.charid     = atoi(row[1]);
			entry.equip_slot = atoi(row[2]);
			entry.item_id    = atoi(row[3]);
			entry.charges    = atoi(row[4]);
			entry.aug_1      = atoi(row[5]);
			entry.aug_2      = atoi(row[6]);
			entry.aug_3      = atoi(row[7]);
			entry.aug_4      = atoi(row[8]);
			entry.aug_5      = atoi(row[9]);
			entry.aug_6      = atoi(row[10]);
			entry.attuned    = atoi(row[11]);

			all_entries.push_back(entry);
		}

		return all_entries;
	}

	static int DeleteWhere(Database& db, std::string where_filter)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {}",
				TableName(),
				where_filter
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int Truncate(Database& db)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"TRUNCATE TABLE {}",
				TableName()
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

};

#endif //EQEMU_BASE_CHARACTER_CORPSE_ITEMS_REPOSITORY_H
