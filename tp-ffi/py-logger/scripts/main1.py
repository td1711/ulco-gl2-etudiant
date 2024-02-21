import Logger
if __name__ == '__main__':

    L = Logger.Logger()
    L.add_item(Logger.Level.Info, 'une info')
    L.add_item(Logger.Level.Error, 'une erreur')
    L.add_item(Logger.Level.Info, 'une autre info')
    L.add_item(Logger.Level.Warning, 'un avertissement')

    L.report_by_added()
    print()
    L.report_by_level()

    # TODO report_by_added

    # TODO report_by_level

